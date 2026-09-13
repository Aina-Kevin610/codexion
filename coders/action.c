/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airandri <airandri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/14 13:35:33 by airandri          #+#    #+#             */
/*   Updated: 2026/09/13 06:58:15 by airandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

void	print_heap(t_coder *coder)
{
	int i = 0;
	printf("[");
	while (coder->dongle->request[i])
	{
		printf("%d ", coder->dongle->request[i]->id_coder);
		i++;
	}
	printf("]\t");

	i = 0;
	printf("[");
	while (coder->prev->dongle->request[i])
	{
		printf("%d ", coder->prev->dongle->request[i]->id_coder);
		i++;
	}
	printf("]\n");
}

void	print_log(t_coder *coder)
{
	pthread_mutex_lock(&(coder->all->lock));
	if (coder->step == 1)
	{
		fprintf(stdout, "%lld %d is compiling \n",
			get_actual_time() - coder->all->start_time, coder->id);
		print_heap(coder);
	}
	else if (coder->step == 2)
		fprintf(stdout, "%d is debugging\n", coder->id);
	else if (coder->step == 3)
		fprintf(stdout, "%d is debugging\n", coder->id);
	else
		printf("none\n");
	pthread_mutex_unlock(&(coder->all->lock));
}

int	compile(t_coder *coder)
{
	coder->have_debug = 0;
	if (coder->compile_done >= coder->all->arguments->nb_compiles)
		return (0);
	if (coder->dongle_hold == 2 && coder->have_compiled == 0)
	{
		print_log(coder);
		coder->compile_done++;
		coder->have_compiled = 1;
		coder->step = 2;
		usleep(coder->all->arguments->compile);
		return (1);
	}
	return (0);
}

int	debug(t_coder *coder)
{
	coder->have_refact = 0;
	if (coder->have_debug == 0 && coder->have_compiled == 1)
	{
		print_log(coder);
		coder->have_debug = 1;
		coder->step = 3;
		usleep(coder->all->arguments->debug);
		return (1);
	}
	return (0);
}

int	refactor(t_coder *coder)
{
	coder->have_compiled = 0;
	if (coder->have_refact == 0 && coder->have_debug == 1)
	{
		print_log(coder);
		coder->have_refact = 1;
		coder->step = 1;
		usleep(coder->all->arguments->refactor);
		return (1);
	}
	return (0);
}
