/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airandri <airandri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/14 13:35:45 by airandri          #+#    #+#             */
/*   Updated: 2026/08/15 21:04:52 by airandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

void	process(t_all *all)
{
	printf("Processing...\n");
	printf("%d", all->coder->id);
}

void	start_simulation(t_all *all)
{
	t_coder	*coder;

	if (!all)
		return;
	coder = all->coder;
	while (coder)
	{
		pthread_create(&coder->thread, NULL, (void *)process, all);
		coder = coder->next;
	}
	
}