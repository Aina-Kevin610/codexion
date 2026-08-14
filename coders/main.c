/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airandri <airandri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 10:02:07 by airandri          #+#    #+#             */
/*   Updated: 2026/08/14 15:22:10 by airandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

int	main(int argc, char *argv[])
{
	t_all	all;
	t_args arguments;
	long long time_0;

	pthread_mutex_init(&all.lock, NULL);
	all.arguments = &arguments;
	all.coder = NULL;
	all.stop = 0;
	time_0 = get_actual_time();
	printf("%lld\n", time_0);
	if (argc != 9)
	{
		ft_error("Invalid arguments!");
		return (0);
	}
	*(all.arguments) = parsing(argv, all.arguments);
	if (all.arguments->error)
	{
		ft_error("Invalid arguments!");
		return (0);
	}
	linking_coder(&all);
	init_coder_id(all.coder);
	pthread_mutex_destroy(&all.lock);
	print_coders(all.coder);
	free_coders(all.coder);
	return (0);
}
