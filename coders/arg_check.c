/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airandri <airandri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 10:40:12 by airandri          #+#    #+#             */
/*   Updated: 2026/07/02 16:04:06 by airandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

void	*number_check(char *coder)
{
	int	i;
	void	*res;

	i = 0;
	res = NULL;
	while (coder[i])
	{
		if (!is_digit(coder[i]))
		{
			ft_error("must be a number and not null");
			return 0;
		}
		i++;
	}
	res = (void *) atoi(coder);
	if (i <= 0)
	{
		ft_error("must be > 0\n");
		return 0;
	}
	return res;
}