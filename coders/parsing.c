/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airandri <airandri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 10:18:16 by airandri          #+#    #+#             */
/*   Updated: 2026/07/03 22:47:47 by airandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

int is_digit(char c)
{
    return (c <= '9' && c >= '0');
}

int	ft_error(char *message)
{
	int	result;

	result = fprintf(stderr, "Error - %s", message);
	return (result);
}

int	number_check(char *coder)
{
	int	i;

	i = 0;
	while (coder[i])
	{
		if (!is_digit(coder[i]))
		{
			ft_error("must be a number and not null");
			return (0);
		}
		i++;
	}
	return (1);
}

int	parsing(char **arg)
{
	if (
		number_check(arg[1]) &&
		number_check(arg[2]) &&
		number_check(arg[3]) &&
		number_check(arg[4]) &&
		number_check(arg[5]) &&
		number_check(arg[6]) &&
		number_check(arg[7]) &&
		(!strcmp(arg[8], "fifo") || !strcmp(arg[8], "edf"))
	)
	{
		return (1);
	}
	return (0);
}