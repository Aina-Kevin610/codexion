/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airandri <airandri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/14 13:35:45 by airandri          #+#    #+#             */
/*   Updated: 2026/08/16 03:10:34 by airandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

void	*process(void *coders)
{
	t_coder	*coder;

	coder = (t_coder *)coders;
	if (!coders)
	{
		printf("ERROR - Processing failed");
		return (NULL);
	}
	//take dongle
	pthread_mutex_lock(&coder->dongle->lock);
	if (coder->dongle->busy == 0)
	{
		coder->dongle_hold += 1;
		coder->dongle->busy = 1;
		fprintf(stdout, "%d has taken a dongle\n", coder->id);
	}
	if (coder->prev->dongle->busy == 0)
	{
		coder->dongle_hold += 1;
		coder->prev->dongle->busy = 1;
		fprintf(stdout, "%d has taken a dongle\n", coder->id);
	}
	pthread_mutex_unlock(&coder->dongle->lock);

	//compile
	compile(coder);
	//debug
	debug(coder);
	//refactor
	refactor(coder);
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