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

int take_dongle(t_coder *coder)
{
	pthread_mutex_lock(coder->all->lock);
	if (!coder)
	{
		pthread_mutex_unlock(coder->all->lock);
		return (0);
	}
	if (coder->dongle->request[0]->id_coder == coder->id_coder)
	{
		// remove request from heap
		coder->dongle_hold++;
	}
	pthread_mutex_unlock(*(coder->all->lock));
	return (coder->dongle_hold);
}