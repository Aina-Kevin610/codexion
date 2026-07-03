/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: A.kevin <A.kevin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 10:18:16 by airandri          #+#    #+#             */
/*   Updated: 2026/07/03 22:14:39 by A.kevin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

void	parsing(char **arg)
{
	int	coder;
	int bot;
	if (
		number_check(arg[1]) &&
		number_check(arg[2])
	)
	{
		coder = number_check(arg[1]);
		bot = number_check(arg[2]);
		printf("number of coder: %d\n", coder);
		printf("burn out time: %d\n", bot);
	}
}