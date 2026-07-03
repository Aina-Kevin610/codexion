/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airandri <airandri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 10:40:12 by airandri          #+#    #+#             */
/*   Updated: 2026/07/03 22:35:45 by airandri         ###   ########.fr       */
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
	return (1);
}