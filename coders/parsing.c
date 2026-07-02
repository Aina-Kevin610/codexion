/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airandri <airandri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 10:18:16 by airandri          #+#    #+#             */
/*   Updated: 2026/07/02 10:57:25 by airandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

void	parsing(char **arg)
{
	int	coder;
	
	if (coder_number_check(arg[1]))
	{
		coder = coder_number_check(arg[1]);	
		printf("%d", coder);
	}
}