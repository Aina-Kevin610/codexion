/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codexion.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airandri <airandri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 09:58:06 by airandri          #+#    #+#             */
/*   Updated: 2026/08/20 15:42:17 by airandri         ###   ########.fr       */
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

typedef struct s_coder		t_coder;
typedef struct s_request	t_request;
typedef struct s_all		t_all;

typedef struct t_scheduler
{
	int			fifo;
	int			edf;
}	t_scheduler;

typedef struct dongle
{
	int				id;
	int				busy;
	int				heap_size;
	long long		free_at;
	t_request		*request[2];
}	t_dongle;

typedef struct s_args
{
	int				coders;
	int				burnout;
	int				compile;
	int				debug;
	int				refactor;
	int				nb_compiles;
	int				dongle_cooldown;
	int				error;
	t_scheduler		scheduler;
}	t_args;

typedef struct s_coder
{
	int				id;
	int				is_burnout;
	int				compile_done;
	int				have_compiled;
	int				have_debug;
	int				have_refact;
	int				dongle_hold;
	t_args			*argument;
	pthread_t		thread;
	t_dongle		*dongle;
	t_coder			*next;
	t_coder			*prev;
	long long		last_compile_start;
	t_all			*all;
	t_request		*request;
}	t_coder;

typedef struct s_all
{
	t_args			*arguments;
	t_coder			*coder;
	int				stop;
	long long		start_time;
	pthread_mutex_t	lock;
	pthread_cond_t	cond;
}	t_all;

typedef struct s_request
{
	int			id_coder;
	int			deadline;
	int			request_time;
	t_request	*parent;
	t_request	*child;	
}	t_request;

int			is_digit(char c);
int			check_arg(char **argv);
int			ft_error(char *message);
int			number_check(char *coder);
int			is_simulation_finished(t_all *all);
int			compile(t_coder *coder);
int			refactor(t_coder *coder);
int			debug(t_coder *coder);
int			take_dongle(t_coder *coder);
void		put_down_dongle(t_coder *coder);
void		print_args(t_args *args);
void		print_coders(t_coder *coder);
void		assign_arg(char **init, t_args *arg);
void		linking_coder(t_all *coder);
void		*process(void *coder);
void		init_coder_id(t_coder *coder);
void		free_coders(t_coder *coder);
void		start_simulation(t_all *all);
void		*monitor(void *ptr);
t_args		parsing(char **argument, t_args *arg);
long long	get_actual_time(void);

//request
t_request	*create_request(t_coder *coder);
void		heap_push(t_dongle *dongle, t_request *req, t_scheduler *sch);
int			request(t_coder *coder);
t_request	*heap_top(t_dongle *dongle);
void		heap_remove(t_dongle *dongle, t_request *req);
#endif
