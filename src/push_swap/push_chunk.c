/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_chunk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <aroque@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 22:55:52 by aroque            #+#    #+#             */
/*   Updated: 2021/04/18 21:15:05 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stack.h"

void sort_pivot_push(t_stack *from, t_stack *to, int mid, int chunk_size)
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

/*
** Find index of numbers to be sent to
** another stack. Return the one to send
** with less instructions.
*/

int abs(int n)
{
	int mask;

	mask = n >> 31;
	return ((n ^ mask) - mask);
}

void	push_closest(int p, t_stack *a, t_stack *b)
{
	int index[2];
	int diff[2];
	int	i;

	i = a->top;
	while (a->array[i] < p)
		i--;
	index[0] = i;
	diff[0] = abs(a->top + 1 - i);
	i = 0;
	while (a->array[i] < p)
		i++;
	index[1] = i;
	diff[1] = abs(a->top + 1 - i);
	if (diff[0] < diff[1])
		run_n(RA, a, b, diff[0]);
	else
		run_n(RRA, a, b, diff[1]);
	run(PB, a, b);
}

void	push_chunk(t_stack *a, t_stack *b)
{
	int	p;
	int	chunk_size;

	if (a->top <= 1)
	{
		if (a->top == 1 && a->array[0] > a->array[1])
			run(SA, a, b);
	}
	else
	{
		p = pivot(a->array, a->top + 1);
		chunk_size = a->top / 2 + a->top % 2;
		sort_pivot_push(a, b, p, chunk_size);
		push_chunk(a, b);
		//pull_chunk(a, b, chunk_size);
	}
}
