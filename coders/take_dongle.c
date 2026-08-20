/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_dongle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airandri <airandri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/20 15:13:51 by airandri          #+#    #+#             */
/*   Updated: 2026/08/20 15:44:59 by airandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

static int	dongle_ready(t_dongle *dongle, long long now)
{
	return (!dongle->busy && now >= dongle->free_at);
}

static int	is_my_turn(t_coder *coder, t_request *req)
{
	int	res;

	res = (heap_top(coder->dongle) == req
			&& heap_top(coder->prev->dongle) == req);
	return (res);
}

int	take_dongle(t_coder *coder)
{
	t_request	*req;
	long long	now;

	pthread_mutex_lock(&coder->all->lock);
	req = coder->request;
	while (!coder->all->stop && !(dongle_ready(coder->dongle, get_actual_time())
			&& dongle_ready(coder->prev->dongle, get_actual_time())
			&& is_my_turn(coder, req)))
		pthread_cond_wait(&coder->all->cond, &coder->all->lock);
	heap_remove(coder->dongle, req);
	heap_remove(coder->prev->dongle, req);
	if (coder->all->stop)
	{
		free(req);
		coder->request = NULL;
		pthread_mutex_unlock(&coder->all->lock);
		return (0);
	}
	coder->dongle->busy = 1;
	coder->prev->dongle->busy = 1;
	coder->dongle_hold = 2;
	free(req);
	coder->request = NULL;
	now = get_actual_time();
	fprintf(stdout, "%lld %d has taken a dongle\n",
		now - coder->all->start_time,
		coder->id);
	fprintf(stdout, "%lld %d has taken a dongle\n",
		now - coder->all->start_time,
		coder->id);
	pthread_mutex_unlock(&coder->all->lock);
	return (1);
}

void	put_down_dongle(t_coder *coder)
{
	long long	now;

	pthread_mutex_lock(&coder->all->lock);
	now = get_actual_time();
	coder->dongle->busy = 0;
	coder->dongle->free_at = now + coder->argument->dongle_cooldown;
	coder->prev->dongle->busy = 0;
	coder->prev->dongle->free_at = now + coder->argument->dongle_cooldown;
	coder->dongle_hold = 0;
	pthread_cond_broadcast(&coder->all->cond);
	pthread_mutex_unlock(&coder->all->lock);
}
