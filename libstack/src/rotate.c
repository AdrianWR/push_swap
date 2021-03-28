/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <aroque@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 18:23:08 by aroque            #+#    #+#             */
/*   Updated: 2021/03/28 18:44:40 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	rotate(t_stack *stack)
{
	unsigned	i;
	int			tmp;

	i = stack->top + 1;
	tmp = stack->array[stack->top];
	while (--i)
		stack->array[i] = stack->array[i - 1];
	stack->array[0] = tmp;
}

void	reverse_rotate(t_stack *stack)
{
	int	i;
	int	tmp;

	i = -1;
	tmp = stack->array[0];
	while (++i < stack->top)
		stack->array[i] = stack->array[i + 1];
	stack->array[stack->top] = tmp;
}
