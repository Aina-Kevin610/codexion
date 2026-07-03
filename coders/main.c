/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airandri <airandri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 10:02:07 by airandri          #+#    #+#             */
/*   Updated: 2026/07/03 22:42:06 by airandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

int main(int argc, char *argv[])
{
    if (argc != 9)
    {
        ft_error("Invalid number of arguments!");
        return 1;
    }
    if (parsing(argv))    
        printf("\nPARSING [OK]...");
    else
        printf("\nPARSING [KO]...");
        
    return 0;
}