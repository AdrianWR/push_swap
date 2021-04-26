/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_chunk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <aroque@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 22:55:52 by aroque            #+#    #+#             */
/*   Updated: 2021/04/25 22:45:14 by aroque           ###   ########.fr       */
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

static int	find_closest_top(int p, t_stack *a, int *diff)
{
	int	i;

	i = a->top;
	while (a->array[i] > p && i >= 0)
		i--;
	*diff = abs(a->top - i);
	return (i);
}

static int	find_closest_down(int p, t_stack *a, int *diff)
{
	int	i;

	i = 0;
	while (a->array[i] > p && i <= a->top)
		i++;
	*diff = abs(i);
	return (i);
}

void	push_to_b(int n, t_stack *a, t_stack *b)
{
	while (b->top > 1 && n > b->array[b->top] && b->array[0] != max(b))
		run(RB, a, b);
	run(PB, a, b);
}

void	push_closest(int p, t_stack *a, t_stack *b)
{
	int	index[2];
	int	diff[2];

	index[0] = find_closest_top(p, a, &diff[0]);
	index[1] = find_closest_down(p, a, &diff[1]);
	if (index[0] == 0 && index[1] == a->top)
		return ;
	if (diff[0] <= diff[1])
		run_n(RA, a, b, diff[0]);
	else
		run_n(RRA, a, b, diff[1] + 1);
	push_to_b(a->top, a, b);
}

void reorder_b(t_stack *b)
{
	int m;

	m = max(b);
	while (b->array[0] != m)
		run(RB, NULL, b);
}

void	push_chunk(t_stack *a, t_stack *b)
{
	int	p;

	if (a->top <= 1)
	{
		if (a->top == 1 && a->array[0] > a->array[1])
			run(SA, a, b);
		run(PB, a, b);
		run(PB, a, b);
	}
	else
	{
		p = pivot(a->array, a->top + 1);
		push_closest(p, a, b);
		reorder_b(b);
		push_chunk(a, b);
	}
}
		
