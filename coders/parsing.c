/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airandri <airandri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 10:18:16 by airandri          #+#    #+#             */
/*   Updated: 2026/07/09 09:40:20 by airandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

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
	if (atoi(number) <= 0)
		return (0);
	return (1);
}

int	parsing(char **arg)
{
	int	i;

	i = 1;
	while (arg[i] && i <= 7)
	{
		if (!number_check(arg[i]))
			return (0);
		i++;
	}
	if (strcmp(arg[8], "fifo") && strcmp(arg[8], "edf"))
		return (0);
	return (1);
}

t_coder	*create_coder(int id)
{
	t_coder	*new_coder;

	new_coder = (t_coder *)malloc(sizeof(t_coder));
	if (!new_coder)
		return (NULL);
	new_coder->id_coder = id;
	new_coder->dongle_hold = 0;
	new_coder->next = NULL;
	return (new_coder);
}

void	add_coder(t_coder *coder)
{
	t_coder *temp;

	temp = coder;
	while(temp->next)
	{
		temp = temp->next;
	}
	temp->next = create_coder(0);
}

t_coder	*sat_coder(int coder_number, t_coder *coder)
{
	int		i;

	i = 1;
	if (!coder)
	{
		coder = create_coder(0);
		i++;
	}
	while (i <= coder_number)
	{
		add_coder(coder);
		i++;
	}
	return (coder);
}

void	print_coder(t_coder *coder)
{
	t_coder	*temp;

	temp = coder;
	if (!coder)
		return;
	while (temp->next)
	{
		printf("(coder %lu) %d\n", temp->id_coder, temp->dongle_hold);
		temp = temp->next;
	}
	printf("(coder %lu) %d\n", temp->id_coder, temp->dongle_hold);
}