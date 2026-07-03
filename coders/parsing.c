/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airandri <airandri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 10:18:16 by airandri          #+#    #+#             */
/*   Updated: 2026/07/03 22:45:29 by airandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

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
		printf("number of coder [OK]...\n");
		printf("burn out time [OK]...\n");
		printf("time to compile [OK]...\n");
		printf("time to debug [OK]...\n");
		printf("time to refractor [OK]...\n");
		printf("dongle_cooldown [OK]...\n");
		printf("Shedule [OK]...\n");
		return (1);
	}
	return (0);
}