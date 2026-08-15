/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airandri <airandri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/14 13:35:45 by airandri          #+#    #+#             */
/*   Updated: 2026/08/16 00:11:00 by airandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

void	process(t_coder *coder)
{
	if (!coder)
	{
		printf("ERROR - Processing failed");
		return;
	}
	//take dongle
	pthread_mutex_lock(&coder->lock);
	if (!coder->prev->dongle->busy)
	{
		coder->dongle_hold += 1;
		coder->prev->dongle->busy = 1;
	}
	pthread_mutex_unlock(&coder->lock);

	//compile
	compile(coder);
	//debug
	debug(coder);
	//refactor
	refactor(coder);
}

void	start_simulation(t_all *all)
{
	t_coder	*coder;

	if (!all)
		return;
	coder = all->coder;
	while (coder)
	{
		pthread_create(&coder->thread, NULL, (void *)process, coder);
		coder = coder->next;
	}
	coder = all->coder;
	while(coder)
	{
		pthread_join(coder->thread, NULL);
		coder = coder->next;
	}
}