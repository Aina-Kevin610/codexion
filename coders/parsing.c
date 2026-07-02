/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airandri <airandri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 10:18:16 by airandri          #+#    #+#             */
/*   Updated: 2026/07/02 16:05:16 by airandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

void	parsing(char **arg)
{
	int	*coder;
	int *bot;
	if (
		number_check(arg[1]) &&
		number_check(arg[1])
	)
	{
		coder = number_check(arg[1]);
		bot = number_check(arg[2]);
		printf("number of coder: %d", *coder);
		printf("number of coder: %d", *bot);
	}
}