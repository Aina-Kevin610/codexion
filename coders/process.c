/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airandri <airandri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/14 13:35:45 by airandri          #+#    #+#             */
/*   Updated: 2026/08/14 13:38:13 by airandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

static void	routine(t_coder *coder)
{
	compile(coder);
	usleep(coder->arguments->compile);
	coder->compile_done++;
	debug(coder);
	usleep(coder->arguments->debug);
	refactor(coder);
	usleep(coder->arguments->refactor);
}

static void	coder_thread(t_coder *coder)
{
	t_coder	*self;

	if (!coder)
		return ;
	self = coder;
	routine(self);
}

void	process(t_all *all)
{
	t_coder	*tmp;

	if (!all)
		return ;
	tmp = all->coder;
	printf("processing...\n");
	while (tmp)
	{
		pthread_create(&tmp->thread, NULL, (void *)coder_thread, tmp);
		tmp = tmp->next->next;
	}
	tmp = all->coder;
	while (tmp)
	{
		pthread_join(tmp->thread, NULL);
		tmp = tmp->next->next;
	}
}