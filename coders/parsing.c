/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airandri <airandri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 10:18:16 by airandri          #+#    #+#             */
/*   Updated: 2026/07/09 13:58:53 by airandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

t_coder *create_coder()
{
  t_coder *new_coder;
  new_coder = (t_coder *) malloc(sizeof(t_coder));
  if (!new_coder)
    return NULL;
  new_coder->dongle_hold = 0;
  new_coder->next = 0;
  return (new_coder);
}

void  add_coder(t_coder *coder)
{
  t_coder *tmp;

  if (!coder)
    return;
  tmp = coder;
  while(tmp->next)
    tmp = tmp->next;
  tmp->next = create_coder();
}

void  linking_coder(t_all *all)
{
  int i;

  i = 0;
  while(i < (int)all->arguments->coders)
  {
    add_coder(all->coder);
    i++;
  }
}

int	number_check(char *number)
{
	int	i;

	i = 0;
	while (number[i])
	{
		if (!is_digit(number[i]))
			return (0);
		i++;
	}
	if (atoi(number) <= 0 || 2147483647 < atoi(number))
		return (0);
	return (1);
}

void	assign_arg(char **init, t_args *arg)
{
	arg->coders = atoi(init[1]);
	arg->burnout = atoi(init[2]);
	arg->compile = atoi(init[3]);
	arg->debug = atoi(init[4]);
	arg->refactor = atoi(init[5]);
	arg->nb_compiles = atoi(init[6]);
	arg->dongle_cooldown = atoi(init[7]);
	if (!strcmp(init[8], "fifo"))
	{
		arg->scheduler.fifo = 1;
		arg->scheduler.edf = 0;
	}
	else if (!strcmp(init[8], "edf"))
	{
		arg->scheduler.fifo = 0;
		arg->scheduler.edf = 1;
	}
}

t_args	parsing(char **argv, t_args *arg)
{
	if (check_arg(argv))
	{
		assign_arg(argv, arg);
		arg->error = 0;
	}
	else
		arg->error = 1;
	return (*arg);
}

int	check_arg(char **arg)
{
	int	i;

	i = 1;
	while (i <= 7)
	{
		if (!number_check(arg[i]))
			return (0);
		i++;
	}
	if (strcmp(arg[8], "fifo") && strcmp(arg[8], "edf"))
		return (0);
	return (1);
}
