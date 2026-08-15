/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airandri <airandri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 10:02:07 by airandri          #+#    #+#             */
/*   Updated: 2026/08/16 00:10:42 by airandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

int	arg_check(int argc, char *argv[], t_all *all)
{
	if (argc != 9)
		return (1);
	*(all->arguments) = parsing(argv, all->arguments);
	if (all->arguments->error)
		return (1);
	return (0);
}

void	init_all(t_all *all)
{
	t_args	*arguments;
	t_coder	*coder;

	coder = all->coder;
	while(coder)
	{
		pthread_mutex_init(&coder->lock, NULL);
		coder = coder->next;
	}
	arguments = (t_args *) malloc(sizeof(t_args));
	if (!arguments)
	{
		ft_error("ERROR - Allocation error");
		return ;
	}
	all->arguments = arguments;
	all->start_time = get_actual_time();
	all->coder = NULL;
	all->stop = 0;
}

int	main(int argc, char *argv[])
{
	t_all	all;
	init_all(&all);
	if (arg_check(argc, argv, &all))
	{
		ft_error("ERROR - Invalid arguments!");
		return (1);
	}
	linking_coder(&all);
	start_simulation(&all);
	
	t_coder	*coder;
	coder = all.coder;
	while(coder)
	{
		pthread_mutex_destroy(&coder->lock);
		coder = coder->next;
	}
	free_coders(all.coder);
	return (0);
}
