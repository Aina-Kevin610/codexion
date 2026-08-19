/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airandri <airandri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/14 13:35:33 by airandri          #+#    #+#             */
/*   Updated: 2026/08/19 16:12:01 by airandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

int	compile(t_coder *coder)
{
	coder->have_debug = 0;
	if (coder->compile_done >= coder->argument->nb_compiles)
		return (0);
	if (coder->dongle_hold == 2 && coder->have_compiled == 0)
	{
		fprintf(stdout, "%d is compiling\n", coder->id);
		coder->compile_done++;
		coder->have_compiled = 1;
		usleep(coder->argument->compile);
	}
	return (1);
}

int	debug(t_coder *coder)
{
	coder->have_refact = 0;
	if (coder->have_debug == 0 && coder->have_compiled == 1)
	{
		fprintf(stdout, "%d is debugging\n", coder->id);
		coder->have_debug = 1;
		usleep(coder->argument->debug);
		return (1);
	}
	return (0);
}

int	refactor(t_coder *coder)
{
	coder->have_compiled = 0;
	if (coder->have_refact == 0 && coder->have_debug == 1)
	{
		fprintf(stdout, "%d is refactoring\n", coder->id);
		coder->have_refact = 1;
		usleep(coder->argument->refactor);
		return (1);
	}
	return (0);
}

void	take_dongle(t_coder *coder)
{
	pthread_mutex_lock(&coder->dongle->lock);
	pthread_mutex_lock(&coder->prev->dongle->lock);
	if (coder->dongle->busy == 0 && coder->dongle_hold < 2)
	{
		coder->dongle_hold += 1;
		coder->dongle->busy = 1;
		fprintf(stdout, "%d has taken a dongle\n", coder->id);
	}
	if (coder->prev->dongle->busy == 0 && coder->dongle_hold < 2)
	{
		coder->dongle_hold += 1;
		coder->prev->dongle->busy = 1;
		fprintf(stdout, "%d has taken a dongle\n", coder->id);
	}
	pthread_mutex_unlock(&coder->dongle->lock);
	pthread_mutex_unlock(&coder->prev->dongle->lock);
}

void put_down_dongle(t_coder *coder)
{
	pthread_mutex_lock(&coder->dongle->lock);
	pthread_mutex_lock(&coder->prev->dongle->lock);
	if (coder->dongle->busy == 1)
		coder->dongle->busy = 0;		
	if (coder->prev->dongle->busy == 1)
		coder->prev->dongle->busy = 0;
	coder->dongle_hold = 0;
	pthread_mutex_unlock(&coder->dongle->lock);
	pthread_mutex_unlock(&coder->prev->dongle->lock);
	usleep(coder->argument->dongle_cooldown);
}