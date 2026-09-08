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
	if (!(request && coder))
		return (NULL);
	request->coder_id = coder->id;
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
	t_request	*request;
	if (!coder)
		return (0);
	request = create_request(coder);
	coder->dongle->request[coder->dongle->heap_size] = request;
	coder->prev->dongle->request[coder->dongle->heap_size] = request;
	return (1);
}