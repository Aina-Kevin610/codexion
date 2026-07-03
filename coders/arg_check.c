/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: A.kevin <A.kevin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 10:40:12 by airandri          #+#    #+#             */
/*   Updated: 2026/07/03 22:12:38 by A.kevin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

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
	if (i <= 0)
	{
		ft_error("must be > 0\n");
		return (0);
	}
	return (1);
}