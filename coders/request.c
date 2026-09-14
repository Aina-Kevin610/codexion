/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   request.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airandri <airandri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 17:25:18 by airandri          #+#    #+#             */
/*   Updated: 2026/09/14 16:16:52 by airandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

t_request	*create_request(t_coder *coder)
{
	t_request	*request;

	request = malloc(sizeof(t_request));
	if (!(request && coder))
		return (NULL);
	request->id_coder = coder->id;
	request->deadline = 0;
	request->request_time = get_actual_time();
	request->child = NULL;
	request->parent = NULL;
	return (request);
}

// static void	heapify(t_coder *coder)
// {
// 	t_request	*tmp;

// 	if (coder->all->arguments->scheduler->fifo)
// 	{
// 		if (coder->dongle->heap_size == 1)
// 		{
// 			if ()
// 		}
// 	}
// 	else
// 	{

// 	}
// }

int	request(t_coder *coder)
{
	t_request	*req;

	if (!coder)
		return (0);
	req = create_request(coder);
	if (!req)
		return (0);
	pthread_mutex_lock(&coder->dongle->lock);
	if (coder->dongle->heap_size < 2)
		coder->dongle->request[coder->dongle->heap_size++] = req;
	pthread_mutex_unlock(&coder->dongle->lock);
	pthread_mutex_lock(&coder->prev->dongle->lock);
	if (coder->prev->dongle->heap_size < 2)
		coder->prev->dongle->request[coder->prev->dongle->heap_size++] = req;
	pthread_mutex_unlock(&coder->prev->dongle->lock);
	return (1);
}
