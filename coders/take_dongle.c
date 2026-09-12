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

static void	heap_pop(t_dongle *dongle)
{
	dongle->heap_size--;
	dongle->request[dongle->heap_size - 1] = dongle->request[dongle->heap_size];
}

static int	able_to_compile(t_coder *coder)
{
	if (coder->dongle->request[0]->id_coder != coder->id)
		return (0);
	if (coder->prev->dongle->request[0]->id_coder != coder->id)
		return (0);
	coder->dongle_hold += 2;
	heap_pop(coder->dongle);
	heap_pop(coder->prev->dongle);
	return (1);
}

int take_dongle(t_coder *coder)
{
	if (!coder)
		return (0);
	pthread_mutex_lock(&coder->all->lock);
	while (!able_to_compile(coder))
		pthread_cond_wait(&coder->all->cond, &coder->all->lock);
	pthread_mutex_unlock(&(coder->all->lock));
	return (coder->dongle_hold);
}
