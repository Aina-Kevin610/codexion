/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airandri <airandri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/14 13:35:33 by airandri          #+#    #+#             */
/*   Updated: 2026/08/29 16:08:39 by airandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

int	compile(t_coder *coder)
{
	coder->have_debug = 0;
	if (coder->compile_done >= coder->all->arguments->nb_compiles)
		return (0);
	if (coder->dongle_hold == 2 && coder->have_compiled == 0)
	{
		fprintf(stdout, "%d is compiling\n", coder->id);
		coder->compile_done++;
		coder->have_compiled = 1;
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
		fprintf(stdout, "%d is debugging\n", coder->id);
		coder->have_debug = 1;
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
		fprintf(stdout, "%d is refactoring\n", coder->id);
		coder->have_refact = 1;
		usleep(coder->all->arguments->refactor);
		return (1);
	}
	return (0);
}
