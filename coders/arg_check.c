/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airandri <airandri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 10:40:12 by airandri          #+#    #+#             */
/*   Updated: 2026/07/02 10:59:59 by airandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

int	coder_number_check(char *coder)
{
	int	i;

	i = 0;
	while (coder[i])
	{
		if (!is_digit(coder[i]))
		{
			ft_error("number of coder must be 'int' and not null");
			return 0;
		}
		i++;
	}
	i = atoi(coder);
	if (i <= 0)
	{
		ft_error("number of coder must be > 0");
		return 0;	
	}
	return i;
}