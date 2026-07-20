/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codexion.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airandri <airandri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 09:58:06 by airandri          #+#    #+#             */
/*   Updated: 2026/07/09 14:30:31 by airandri         ###   ########.fr       */
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

typedef struct t_scheduler
{
	int	fifo;
	int	edf;
}	t_scheduler;

typedef struct s_coder
{
	int				dongle_hold;
  int       compile_done;
	pthread_t		id_coder;
  long long   last_compile_start;
	struct s_coder	*next;
}	t_coder;

typedef struct s_args
{
	int			coders;
	int			burnout;
	int			compile;
	int			debug;
	int			refactor;
	int			nb_compiles;
	int			dongle_cooldown;
	int			error;
	t_scheduler	scheduler;
}	t_args;

typedef struct s_all
{
	t_args	*arguments;
  t_coder *coder;
  int     stop;
  long long start_time;
  pthread_mutex_t lock;
}	t_all;

int			is_digit(char c);
int 		check_arg(char **argv);
int			ft_error(char *message);
int			number_check(char *coder);
void 		print_args(t_args *args);
void    print_coders(t_coder *coder);
void		assign_arg(char **init, t_args *arg);
void    debug(int time);
void    compile(int time);
void    refactor(int time);
void    linking_coder(t_all *all);
t_args	parsing(char **argument, t_args *arg);
long long	get_actual_time();
#endif
