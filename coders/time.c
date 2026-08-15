/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airandri <airandri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/09 14:21:32 by airandri          #+#    #+#             */
/*   Updated: 2026/08/15 19:06:52 by airandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

long long get_actual_time()
{
	struct timeval  time;

	gettimeofday(&time, NULL);
	return ((long long)time.tv_sec * 1000 + time.tv_usec / 1000);
}
