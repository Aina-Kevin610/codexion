/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airandri <airandri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 10:18:16 by airandri          #+#    #+#             */
/*   Updated: 2026/07/08 15:31:01 by airandri         ###   ########.fr       */
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

t_coder	*create_coder(int num_dongle, int num)
{
	t_coder	*new_coder;

	new_coder = (t_coder *)malloc(sizeof(t_coder));
	if (!new_coder || num_dongle > 2 || num_dongle <= 0)
		return (NULL);
	new_coder->number = num;
	new_coder->dongle_hold = num_dongle;
	new_coder->next = NULL;
	return (new_coder);
}

void	add_coder(t_coder *coder, t_coder *new_coder)
{
	t_coder *temp;

	temp = coder;
	while(temp->next)
	{
		temp = temp->next;
	}
	temp->next = new_coder;
}

t_coder	*sat_coder(int coder_number, t_coder *coder)
{
	int		i;
	t_coder	*new_coder;

	i = 1;
	if (!coder)
	{
		coder = create_coder(0, 0);
		i++;
	}		
	new_coder = NULL;
	while (i <= coder_number)
	{
		new_coder = create_coder(0, i);
		add_coder(coder, new_coder);
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
		printf("(coder %d) %d\n", temp->number, temp->dongle_hold);
		temp = temp->next;
	}
	printf("(coder %d) %d\n", temp->number, temp->dongle_hold);
}