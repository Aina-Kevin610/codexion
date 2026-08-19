/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airandri <airandri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/14 00:00:00 by airandri          #+#    #+#             */
/*   Updated: 2026/08/19 10:47:25 by airandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

int	is_simulation_finished(t_all *all)
{
	t_coder	*tmp;

	tmp = all->coder;
	while (tmp)
	{
		if (tmp->compile_done < all->arguments->nb_compiles)
		{
			all->stop = 0;
			return (0);
		}
		tmp = tmp->next;
	}
	all->stop = 1;
	return (1);
}

void	*monitor(void *ptr)
{
	t_all			*all;
	pthread_mutex_t	lock;
	pthread_cond_t	cond;

	all = (t_all *)ptr;
	pthread_mutex_lock(&lock);
	while(is_simulation_finished(all))
		pthread_cond_wait(&cond, &lock);
	pthread_mutex_unlock(&lock);
	return (NULL);
}
