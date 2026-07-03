/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airandri <airandri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 10:02:07 by airandri          #+#    #+#             */
/*   Updated: 2026/07/03 23:02:25 by airandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

int main(int argc, char *argv[])
{
	struct timeval tv;

	gettimeofday(&tv, NULL);
    if (argc != 9 && !parsing(argv))
    {
        ft_error("Invalid number of arguments!");
        return (1);
    }
	printf("seconde: %ld\n", tv.tv_sec);
	printf("microseconde: %ld", tv.tv_usec);
    
    return (0);
}