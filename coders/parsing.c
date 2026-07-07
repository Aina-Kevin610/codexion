/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airandri <airandri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 10:18:16 by airandri          #+#    #+#             */
/*   Updated: 2026/07/07 08:49:22 by airandri         ###   ########.fr       */
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

int	number_check(char *number)
{
	int	i;

	i = 0;
	while (number[i])
	{
		if (!is_digit(number[i]))
			return (0);
		i++;
	}
	if (atoi(number) <= 0)
		return (0);
	return (1);
}

int	parsing(char **arg)
{
	int	i;

	i = 1;
	while (arg[i] && i <= 7)
	{
		if (!number_check(arg[i]))
			return (0);
		i++;
	}
	if (strcmp(arg[8], "fifo") && strcmp(arg[8], "edf"))
		return (0);
	return (1);
}
