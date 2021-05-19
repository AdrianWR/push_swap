/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <aroque@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 14:50:26 by aroque            #+#    #+#             */
/*   Updated: 2021/05/19 00:21:58 by aroque           ###   ########.fr       */
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

void move_to_top(t_stack *a, int min, int max)
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

void	move_min_max_to_top(t_stack *b)
{
	int i;
	int index[2];

	index[0] = _index(b, min(b));
	index[1] = _index(b, max(b));
	if (index[0] < b->top - index[1])
		i = index[0];
	else
		i = index[1];
	smart_rotate_b(b, b->array[i]);
}

void	put_in_position(t_stack *a, t_stack *b)
{
	int	top_b;
	int to_move;

	top_b = b->array[b->top];
	to_move = closest_above(a, top_b);
	if (to_move == top_b && a->top >= 0)
		to_move = min(a);
	smart_rotate(a, to_move);
	run(PA, a, b);
}

void	sort_chunk(t_stack *a, t_stack *b)
{
	while (b->top >= 0)
	{
		move_min_max_to_top(b);
		put_in_position(a, b);
	}
}

void	move_chunk(t_stack *a, t_stack *b, int min, int max)
{
	int size;

	size = max - min + 1;
	while (size)
	{
		move_to_top(a, min, max);
		run(PB, a, b);
		size--;
	}
}

size_t	get_chunks(t_stack *a)
{
	size_t	chunks;
	
	(void) a;
	chunks = 2;
	return (chunks);
}

void	sort_complex(t_stack *a, t_stack *b)
{
	int	limit_min;
	int	limit_max;
	size_t	chunks;
	size_t	step;

	chunks = get_chunks(a);
	limit_min = min(a);
	step = (a->top + 1) / chunks;
	while (chunks >= 1)
	{
		if (chunks == 1)
			limit_max = max(a);
		else 
			limit_max = limit_min + step - 1;
		move_chunk(a, b, limit_min, limit_max);
		sort_chunk(a, b);
		limit_min = limit_max + 1;
		chunks--;
	}
	smart_rotate(a, min(a));
}
