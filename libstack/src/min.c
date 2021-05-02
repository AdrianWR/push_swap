/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <aroque@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 18:15:39 by aroque            #+#    #+#             */
/*   Updated: 2021/05/01 18:16:36 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

static int	_min(int *array, size_t len)
{
	int	m;

	if (len == 1)
		return (array[0]);
	m = _min(array, len - 1);
	if (array[len - 1] < m)
		m = array[len - 1];
	return (m);
}

int	min(t_stack *stack)
{
	return (_min(stack->array, stack->top + 1));
}
