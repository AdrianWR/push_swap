/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <aroque@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 16:29:30 by aroque            #+#    #+#             */
/*   Updated: 2021/04/25 16:31:16 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

static int	_max(int *array, size_t len)
{
	int	m;

	if (len == 1)
		return (array[0]);
	m = _max(array, len - 1);
	if (array[len - 1] > m)
		m = array[len - 1];
	return (m);
}

int	max(t_stack *stack)
{
	return (_max(stack->array, stack->top + 1));
}
