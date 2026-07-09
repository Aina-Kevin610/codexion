/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airandri <airandri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 10:02:07 by airandri          #+#    #+#             */
/*   Updated: 2026/07/09 14:00:42 by airandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

int main(int argc, char *argv[])
{
	t_all	all;

	if (argc != 9)
	{
		ft_error("Invalid arguments!");
		return (0);
	}
	all.arguments = parsing(argv, &all.arguments);
	if (all.arguments.error)
	{
		ft_error("Invalid arguments!");
		return (0);
	}
	print_args(&(all.arguments));

	return (0);
}
