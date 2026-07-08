/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airandri <airandri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 10:02:07 by airandri          #+#    #+#             */
/*   Updated: 2026/07/08 15:23:25 by airandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

int main(int argc, char *argv[])
{
	t_coder *coder;

	coder = NULL;
	if (argc != 9 || !parsing(argv))
	{
		ft_error("Invalid arguments!");
		return (0);
	}
	coder = sat_coder(atoi(argv[1]), coder);
	print_coder(coder);
	return (0);
}
