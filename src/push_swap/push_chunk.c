/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_chunk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <aroque@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 22:55:52 by aroque            #+#    #+#             */
/*   Updated: 2021/04/11 22:56:40 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stack.h"

void sort_mid_point_push(t_stack *from, t_stack *to, int mid, int chunk_size)
{
	while (from->top >= chunk_size && from->top > 1)
	{
		if (from->array[from->top] < mid)
			run(PB, from, to);
		else if (from->array[0] < mid)
		{
			run(RRA, from, to);
			run(PB, from, to);
		}
		else
			run(RA, from, to);
	}
}

void	push_chunk(t_stack *a, t_stack *b)
{
	int	mid;
	int	chunk_size;

	if (a->top <= 1)
	{
		if (a->top == 1 && a->array[0] > a->array[1])
			run(SA, a, b);
	}
	else
	{
		mid = mid_point(a->array, a->top + 1);
		chunk_size = a->top / 2 + a->top % 2;
		sort_mid_point_push(a, b, mid, chunk_size);
		push_chunk(a, b);
		pull_chunk(a, b, chunk_size);
	}
}
