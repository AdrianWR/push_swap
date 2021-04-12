/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <aroque@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 21:08:50 by aroque            #+#    #+#             */
/*   Updated: 2021/04/11 22:58:59 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "push_swap.h"
#include "libft.h"
#include "stack.h"
#include "general.h"

#include <stdio.h>

void sort_mid_point_pull(t_stack *a, t_stack *b, int mid, int chunk_size)
{
	while (b->top < chunk_size && b->top > 1)
	{
		if (b->array[b->top] < mid)
			run(PA, a, b);
		else if (b->array[b->top - chunk_size] < mid)
		{
			run(RRB, a, b);
			run(PA, a, b);
		}
		else
			run(RB, a, b);
		printf("B TOP -> %d\n", b->top);
	}
}


void	pull_chunk(t_stack *a, t_stack *b, int chunk_size)
{
	int	mid;
	int	start;

	printf("b top: %d\n", b->top);
	if (chunk_size == 1)
		run(PA, a, b);
	else
	{
		start = b->top - chunk_size + 1;
		mid = mid_point(b->array + start, chunk_size);
		sort_mid_point_pull(b, a, mid, chunk_size);
	}
}


void	sort(t_stack *stack)
{
	t_stack	*new;

	new = initialize(stack->size);
	push_chunk(stack, new);
	free_stack(new);
}
