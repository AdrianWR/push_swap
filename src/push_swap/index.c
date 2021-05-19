/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <aroque@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 11:48:02 by aroque            #+#    #+#             */
/*   Updated: 2021/05/19 15:00:44 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "general.h"
#include "libft.h"

static int	*sorted_array_copy(t_stack *stack)
{
	int		*copy;
	size_t	size;

	size = stack->top + 1;
	copy = malloc(size * sizeof(*copy));
	ft_memcpy(copy, stack->array, size * sizeof(*copy));
	insertion_sort(copy, size);
	return (copy);
}

void	index_stack(t_stack **stack)
{
	int		*copy;
	int		i;
	size_t	pos;
	int		array[(*stack)->top + 1];

	i = 0;
	copy = sorted_array_copy(*stack);
	while (i <= (*stack)->top)
	{
		pos = 0;
		while (copy[pos] != (*stack)->array[i])
			pos++;
		array[i++] = pos;
	}
	free(copy);
	ft_memcpy((*stack)->array, array, ((*stack)->top + 1) * sizeof(*array));
}

int _index(t_stack *stack, int n)
{
	int i;

	i = stack->top;
	while (stack->array[i] != n && i >= 0)
		i--;
	return (i);
}
