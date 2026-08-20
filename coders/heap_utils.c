/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airandri <airandri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/20 15:24:22 by airandri          #+#    #+#             */
/*   Updated: 2026/08/20 15:43:28 by airandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

static int	shift_if_match(t_dongle *dongle, t_request *req)
{
	if (dongle->request[0] == req)
	{
		dongle->request[0] = dongle->request[1];
		return (1);
	}
	if (dongle->heap_size == 2 && dongle->request[1] == req)
		return (1);
	return (0);
}

void	heap_remove(t_dongle *dongle, t_request *req)
{
	if (dongle->heap_size == 0)
		return ;
	if (shift_if_match(dongle, req))
		dongle->heap_size--;
}

static int	has_priority(t_scheduler *sch, t_request *a, t_request *b)
{
	if (sch->edf)
		return (a->deadline < b->deadline);
	return (a->request_time < b->request_time);
}

void	heap_push(t_dongle *dongle, t_request *req, t_scheduler *sch)
{
	t_request	*tmp;

	dongle->request[dongle->heap_size] = req;
	dongle->heap_size++;
	if (dongle->heap_size == 2
		&& has_priority(sch, dongle->request[1],
			dongle->request[0]))
	{
		tmp = dongle->request[0];
		dongle->request[0] = dongle->request[1];
		dongle->request[1] = tmp;
	}
}

t_request	*heap_top(t_dongle *dongle)
{
	if (dongle->heap_size == 0)
		return (NULL);
	return (dongle->request[0]);
}
