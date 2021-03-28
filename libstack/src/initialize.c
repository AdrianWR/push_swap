/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <aroque@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 14:48:36 by aroque            #+#    #+#             */
/*   Updated: 2021/03/28 15:36:53 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

t_stack	*initialize(unsigned int size)
{
	t_stack	*stack;

	if (!(stack = malloc(sizeof(*stack))))
		return (NULL);
	if (!(stack->array = malloc(size * sizeof(*(stack->array)))))
		return (NULL);
	stack->size = size;
	stack->top = -1;
	return (stack);
}
