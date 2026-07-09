/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codexion.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airandri <airandri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 09:58:06 by airandri          #+#    #+#             */
/*   Updated: 2026/07/09 09:37:06 by airandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CODEXION_H
# define CODEXION_H
# include <unistd.h>
# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>

typedef struct s_coder
{
	int				dongle_hold;
	pthread_t		id_coder;
	struct s_coder	*next;
}					t_coder;

int		is_digit(char c);
int 	parsing(char **argv);
int		ft_error(char *message);
int		number_check(char *coder);
t_coder	*create_coder(int id);
t_coder	*sat_coder(int coder_number, t_coder *coder);
void	print_coder(t_coder *coder);
void	add_coder(t_coder *coder);

#endif