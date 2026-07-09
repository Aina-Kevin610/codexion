/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airandri <airandri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/09 10:26:43 by airandri          #+#    #+#             */
/*   Updated: 2026/07/09 11:38:18 by airandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

void print_args(t_args *args)
{
    if (args == NULL)
    {
        printf("Erreur : l'argument est NULL.\n");
        return;
    }

    printf("------------------------------\n");
    printf("Coders          : %d\n", args->coders);
    printf("Burnout         : %d\n", args->burnout);
    printf("Compile         : %d\n", args->compile);
    printf("Debug           : %d\n", args->debug);
    printf("Refactor        : %d\n", args->refactor);
    printf("Nb Compiles     : %d\n", args->nb_compiles);
    printf("Dongle Cooldown : %d\n", args->dongle_cooldown);
    
    printf("FIFO            : %d\n", args->scheduler.fifo);
    printf("EDF             : %d\n", args->scheduler.edf);
    printf("------------------------------\n");
}

// void	print_coder(t_coder *coder)
// {
// 	t_coder	*temp;

// 	temp = coder;
// 	if (!coder)
// 		return;
// 	while (temp->next)
// 	{
// 		printf("(coder %lu) %d\n", temp->id_coder, temp->dongle_hold);
// 		temp = temp->next;
// 	}
// 	printf("(coder %lu) %d\n", temp->id_coder, temp->dongle_hold);
// }