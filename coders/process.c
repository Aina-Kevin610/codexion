/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airandri <airandri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/14 13:35:45 by airandri          #+#    #+#             */
/*   Updated: 2026/08/19 10:48:55 by airandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

int	act(t_coder *coder)
{
	int	signal;

	signal = 1;
	coder->have_compiled = 0;
	take_dongle(coder);
	signal *= compile(coder);
	put_down_dongle(coder);
	if (!signal)
		return (signal);
	signal *= debug(coder);
	signal *= refactor(coder);
	return (signal);
}

void	*process(void *coders)
{
	int		check;
	t_coder	*coder;

	if (!coders)
	{
		printf("ERROR - Processing failed");
		return (NULL);
	}
	coder = (t_coder *)coders;
	check = 1;
	while(check)
		check = act(coder);
	return (NULL);
}

void	start_simulation(t_all *all)
{
	t_coder	*coder;

	if (!all)
		return;
	coder = all->coder;
	while (coder)
	{
		pthread_create(&coder->thread, NULL, process, (void *)coder);
		coder = coder->next;
	}
	coder = all->coder;
	while(coder)
	{
		pthread_join(coder->thread, NULL);
		coder = coder->next;
	}
}
