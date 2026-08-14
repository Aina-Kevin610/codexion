/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airandri <airandri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/14 13:35:33 by airandri          #+#    #+#             */
/*   Updated: 2026/08/14 13:35:34 by airandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

void  compile(t_coder *coder)
{
  printf("%d is Compiling...\n", coder->id);
}

void  debug(t_coder *coder)
{
  printf("%d is Debuging...\n", coder->id);
}

void  refactor(t_coder *coder)
{
  printf("%d is Refactoring...\n", coder->id);
}

