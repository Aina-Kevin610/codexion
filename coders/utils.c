/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airandri <airandri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/09 10:26:43 by airandri          #+#    #+#             */
/*   Updated: 2026/07/09 13:35:15 by airandri         ###   ########.fr       */
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

int is_digit(char c)
{
    return (c <= '9' && c >= '0');
}

int	ft_error(char *message)
{
	int	result;

	result = fprintf(stderr, "Error - %s", message);
	return (result);
}

void	print_coders(t_coder *coder)
{
 	t_coder	*temp;

 	temp = coder;
 	if (!coder)
  {
    printf("No coder found");
    return;
  }
 	while (temp->next)
 	{
 		printf("(coder %d) %d\n", temp->id, temp->dongle_hold);
 		temp = temp->next;
 	}
 	printf("(coder %d) %d\n", temp->id, temp->dongle_hold);
}

void	free_coders(t_coder *coder)
{
	t_coder	*tmp;

	while (coder)
	{
		tmp = coder->next;
		free(coder);
		coder = tmp;
	}
}
