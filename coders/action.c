/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airandri <airandri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/14 13:35:33 by airandri          #+#    #+#             */
/*   Updated: 2026/09/14 16:58:59 by airandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

void	print_heap(t_coder *coder)
{
	int i;

	i = 0;
	printf("[");
	while (i < coder->dongle->heap_size)
	{
		printf("%d ", coder->dongle->request[i]->id_coder);
		i++;
	}
	printf("]\t");
	i = 0;
	printf("[");
	while (i < coder->prev->dongle->heap_size)
	{
		printf("%d ", coder->prev->dongle->request[i]->id_coder);
		i++;
	}
	printf("]\n");
}

void	print_log(t_coder *coder, int step)
{
	pthread_mutex_lock(&(coder->all->lock));
	if (step == 1)
	{
		fprintf(stdout, "%lld %d is compiling \n",
			get_actual_time() - coder->all->start_time, coder->id);
		print_heap(coder);
	}
	else if (step == 2)
	{
		fprintf(stdout, "%lld %d is debugging\n",
			get_actual_time() - coder->all->start_time, coder->id);
		print_heap(coder);
	}
	else if (step == 3)
	{
		fprintf(stdout, "%lld %d is refactoring\n",
			get_actual_time() - coder->all->start_time, coder->id);
		print_heap(coder);	
	}
	else if (step == 4)
	{
		fprintf(stdout, "%lld %d has taken a dongle\n",
			get_actual_time() - coder->all->start_time, coder->id);
		print_heap(coder);
	}
	else
		printf("none\n");
	pthread_mutex_unlock(&(coder->all->lock));
}

int	compile(t_coder *coder)
{
	if (coder->compile_done >= coder->all->arguments->nb_compiles)
		return (0);
	if (coder->dongle_hold == 2 && coder->step == 1)
	{
		print_log(coder, coder->step);
		coder->compile_done++;
		coder->step = 2;
		usleep(coder->all->arguments->compile);
		return (1);
	}
	return (0);
}

int	debug(t_coder *coder)
{
	if (coder->step == 2)
	{
		print_log(coder, coder->step);
		coder->step = 3;
		usleep(coder->all->arguments->debug);
		return (1);
	}
	return (0);
}

int	refactor(t_coder *coder)
{
	if (coder->step == 3)
	{
		print_log(coder, coder->step);
		coder->step = 1;
		usleep(coder->all->arguments->refactor);
		return (1);
	}
	return (0);
}
