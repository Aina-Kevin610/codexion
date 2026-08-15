/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airandri <airandri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 10:02:07 by airandri          #+#    #+#             */
/*   Updated: 2026/08/15 21:49:40 by airandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

int	arg_check(int argc, char *argv[], t_all *all)
{
	if (argc != 9)
	{
		ft_error("Invalid arguments!");
		return (1);
	}
	*(all->arguments) = parsing(argv, all->arguments);
	if (all->arguments->error)
	{
		ft_error("Invalid arguments!");
		return (1);
	}
	return (0);
}

void	init_all(t_all *all)
{
	t_args	*arguments;
	
	arguments = (t_args *) malloc(sizeof(t_args));
	if (!arguments)
	{
		ft_error("ERROR - Allocation error");
		return ;
	}
	all->arguments = arguments;
	all->coder = NULL;
	all->stop = 0;
}

int	main(int argc, char *argv[])
{
	t_all	all;
	long long time_0;

	pthread_mutex_init(&all.lock, NULL);

	time_0 = get_actual_time();
	printf("%lld\n", time_0);
	init_all(&all);
	if (arg_check(argc, argv, &all))
	{
		ft_error("Invalid arguments!");
		return (1);
	}
	linking_coder(&all);
	init_coder_id(all.coder);
	pthread_mutex_destroy(&all.lock);
	free_coders(all.coder);
	return (0);
}
