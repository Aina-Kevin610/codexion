/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airandri <airandri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 10:02:07 by airandri          #+#    #+#             */
/*   Updated: 2026/07/07 09:02:18 by airandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

int main(int argc, char *argv[])
{
	t_coder *coder;
	struct timeval tv;

	coder = NULL;
	gettimeofday(&tv, NULL);
	if (argc != 9 || !parsing(argv))
	{
		ft_error("Invalid arguments!");
		return (0);
	}
	printf("seconde: %ld\n", tv.tv_sec);
	printf("microseconde: %ld\n", tv.tv_usec);
	coder = sat_coder(argv(1));
	return (0);
}
