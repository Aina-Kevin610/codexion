/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airandri <airandri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 10:18:16 by airandri          #+#    #+#             */
/*   Updated: 2026/07/03 22:53:47 by airandri         ###   ########.fr       */
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
			ft_error("must be a number and not null\n");
			return (0);
		}
		i++;
	}
	return (1);
}

int	parsing(char **arg)
{
  int i;

  i = 1;
	while (arg[i])
  {
    if (i == 8 && strcmp(arg[i], "fifo"))
      return (0);
    else
      number_check(arg[i]);
    i++;
  }
	return (1);
}
