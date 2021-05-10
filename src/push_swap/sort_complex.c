/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <aroque@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 14:50:26 by aroque            #+#    #+#             */
/*   Updated: 2021/05/10 10:07:07 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stack.h"
#include <stdio.h>

int	between(int n, int min, int max)
{
	return (n >= min && n <= max);
}

int find_from_top(t_stack *a, int min, int max)
{
	int	i;

	i = 0;
	while (i <= a->top)
	{
		if (between(a->array[i], min, max))
			return (i);
		i++;
	}
	return (-1);
}

int find_from_bottom(t_stack *a, int min, int max)
{
	int	i;

	i = a->top;
	while (i >= 0)
	{
		if (between(a->array[i], min, max))
			return (i);
		i--;
	}
	return (-1);
}

static void move_to_top(t_stack *a, int min, int max)
{
	int i;
	int index[2];

	index[0] = find_from_top(a, min, max);
	index[1] = find_from_bottom(a, min, max);
	if (index[0] < a->top - index[1])
		i = index[0];
	else
		i = index[1];
	smart_rotate(a, a->array[i]);
}

static void	put_in_position(t_stack *a, t_stack *b)
{
	int	top_a;
	int to_move;

	if (b->top >= 0)
	{
		top_a = a->array[a->top];
		to_move = closest_below(b, top_a);
		if (to_move == top_a)
			to_move = max(b);
		smart_rotate_b(b, to_move);
	}
	run(PB, a, b);
}

static void	sort_chunk(t_stack *a, t_stack *b, int min, int max)
{
	int size;

	size = max - min + 1;
	while (size)
	{
		move_to_top(a, min, max);
		put_in_position(a, b);
		size--;
	}
}

size_t	get_chunks(t_stack *a)
{
	size_t	chunks;
	
	(void) a;
	chunks = 5;
	return (chunks);
}

void	sort_complex(t_stack *a, t_stack *b)
{
	int	limit;
	int	size;
	size_t	chunks;

	chunks = get_chunks(a);
	size = a->top + 1;
	while (chunks > 1)
	{
		limit = size / chunks - 1;
		sort_chunk(a, b, min(a), limit);
		chunks--;
	}
	sort_chunk(a, b, min(a), max(a));
	smart_rotate_b(b, max(b));
	while (b->top >= 0)
		run(PA, a, b);
}
