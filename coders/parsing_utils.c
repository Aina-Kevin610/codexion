/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airandri <airandri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/20 15:20:16 by airandri          #+#    #+#             */
/*   Updated: 2026/08/20 15:21:06 by airandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

void	init_coder_id(t_coder *coder)
{
	t_coder	*tmp;
	int		i;

	if (!coder)
		return ;
	i = 1;
	tmp = coder;
	while (tmp)
	{
		tmp->id = i;
		tmp->dongle->id = i;
		tmp->dongle_hold = 0;
		tmp->compile_done = 0;
		tmp = tmp->next;
		i++;
	}
}

t_coder	*create_coder(void)
{
	t_coder		*new_coder;
	t_dongle	*new_dongle;

	new_dongle = (t_dongle *) malloc(sizeof(t_dongle));
	if (!new_dongle)
		return (NULL);
	new_coder = (t_coder *) malloc(sizeof(t_coder));
	if (!new_coder)
	{
		free(new_dongle);
		return (NULL);
	}
	new_coder->dongle = new_dongle;
	new_coder->prev = NULL;
	new_coder->next = NULL;
	return (new_coder);
}

void	add_coder(t_coder *coder)
{
	t_coder	*tmp;

	if (!coder)
		return ;
	tmp = coder;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = create_coder();
	if (tmp->next)
		tmp->next->prev = tmp;
}

void	linking_coder(t_all *all)
{
	int		i;
	t_coder	*last_coder;

	i = 0;
	while (i < (int)all->arguments->coders)
	{
		if (all->coder)
			add_coder(all->coder);
		else
			all->coder = create_coder();
		i++;
	}
	last_coder = all->coder;
	while (last_coder)
	{
		last_coder->argument = all->arguments;
		last_coder->all = all;
		last_coder = last_coder->next;
	}
	init_coder_id(all->coder);
	last_coder = all->coder;
	while (last_coder->next)
		last_coder = last_coder->next;
	all->coder->prev = last_coder;
}
