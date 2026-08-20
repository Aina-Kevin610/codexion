/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   request.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airandri <airandri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 17:25:18 by airandri          #+#    #+#             */
/*   Updated: 2026/08/20 15:43:21 by airandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

t_request	*create_request(t_coder *coder)
{
	t_request	*request;

	request = malloc(sizeof(t_request));
	if (!request)
		return (NULL);
	request->id_coder = coder->id;
	request->deadline = 0;
	request->request_time = get_actual_time();
	request->parent = NULL;
	request->child = NULL;
	return (request);
}

int	request(t_coder *coder)
{
	t_request	*req;

	pthread_mutex_lock(&coder->all->lock);
	req = create_request(coder);
	if (!req)
	{
		pthread_mutex_unlock(&coder->all->lock);
		return (0);
	}
	req->deadline = (int)(coder->last_compile_start + coder->argument->burnout);
	heap_push(coder->dongle, req, &coder->argument->scheduler);
	heap_push(coder->prev->dongle, req, &coder->argument->scheduler);
	coder->request = req;
	pthread_mutex_unlock(&coder->all->lock);
	return (1);
}
