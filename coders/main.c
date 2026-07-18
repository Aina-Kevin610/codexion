/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airandri <airandri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 10:02:07 by airandri          #+#    #+#             */
/*   Updated: 2026/07/09 15:25:28 by airandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

int main(int argc, char *argv[])
{
	t_all	all;
	long long actual;
  t_args arguments;

  all.arguments = &arguments;
  all.coder = NULL;

	actual = get_actual_time();
  printf("%llu", actual);
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
	//print_args(all.arguments);
  print_coders(all.coder);
  printf("EVETYTHING IS DONE CORECTLY!");
	return (0);
}
