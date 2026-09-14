/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_dongle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airandri <airandri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/20 15:13:51 by airandri          #+#    #+#             */
/*   Updated: 2026/09/14 17:08:15 by airandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

static void	heap_pop(t_dongle *dongle)
{
	dongle->heap_size--;
	dongle->request[dongle->heap_size - 1] = dongle->request[dongle->heap_size];
}

static int	able_to_compile(t_coder *coder)
{
	if (coder->dongle->request[0]->id_coder == coder->id
	&& coder->dongle->busy == 0)
	{
		coder->dongle_hold++;
		coder->dongle->busy = 1;
		print_log(coder, 4);
		heap_pop(coder->dongle);
		return (1);
	}
	return (0);
}

int take_dongle(t_coder *coder)
{
	pthread_mutex_lock(&coder->dongle->lock);
	while (able_to_compile(coder) == 0)
		pthread_cond_wait(&coder->dongle->cond, &coder->dongle->lock);
	pthread_mutex_unlock(&(coder->dongle->lock));
	pthread_mutex_lock(&coder->prev->dongle->lock);
	while (able_to_compile(coder->prev) == 0)
		pthread_cond_wait(&coder->prev->dongle->cond, &coder->prev->dongle->lock);
	pthread_mutex_unlock(&(coder->prev->dongle->lock));
	return (coder->dongle_hold);
}

void	release_dongle(t_coder *coder)
{
	pthread_mutex_lock(&coder->dongle->lock);
	coder->dongle->busy = 0;
	coder->dongle_hold--;
	pthread_cond_broadcast(&coder->dongle->cond);
	pthread_mutex_unlock(&coder->dongle->lock);
	pthread_mutex_lock(&coder->prev->dongle->lock);
	coder->prev->dongle->busy = 0;
	coder->dongle_hold--;
	pthread_cond_broadcast(&coder->prev->dongle->cond);
	pthread_mutex_unlock(&coder->prev->dongle->lock);
}