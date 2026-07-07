/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airandri <airandri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 10:02:07 by airandri          #+#    #+#             */
/*   Updated: 2026/07/07 08:36:52 by airandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

int main(int argc, char *argv[])
{
	struct timeval tv;

	gettimeofday(&tv, NULL);
  if (argc != 9 || !parsing(argv))
  {
    ft_error("Invalid arguments!");
    return (0);
  }
	printf("seconde: %ld\n", tv.tv_sec);
	printf("microseconde: %ld\n", tv.tv_usec);
  printf("hello");
  return (0);
}
