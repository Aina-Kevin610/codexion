/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airandri <airandri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/14 13:35:33 by airandri          #+#    #+#             */
/*   Updated: 2026/08/16 03:09:23 by airandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

void	compile(t_coder *coder)
{
	if (coder->dongle_hold == 2)
		fprintf(stdout, "%d is Compiling (number of dongle hold %d)\n", coder->id, coder->dongle_hold);
	else
		fprintf(stdout, "%d is OK OK OK (number of dongle hold %d)\n", coder->id, coder->dongle_hold);
}

void	debug(t_coder *coder)
{
	printf("%d is Debuging\n", coder->id);
}

void	refactor(t_coder *coder)
{
	printf("%d is Refactoring\n", coder->id);
}

