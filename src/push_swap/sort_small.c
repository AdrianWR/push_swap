/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <aroque@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 16:52:54 by aroque            #+#    #+#             */
/*   Updated: 2021/05/02 16:59:45 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "push_swap.h"

static void	sort_tri(t_stack *a)
{
	int	*arr;

	arr = a->array;
	if (arr[0] > arr[1] && arr[1] < arr[2] && arr[2] < arr[0])
		run(SA, a, NULL);
	else if (arr[0] < arr[1] && arr[1] < arr[2] && arr[2] > arr[0])
	{
		run(SA, a, NULL);
		run(RRA, a, NULL);
	}
	else if (arr[0] > arr[1] && arr[1] < arr[2] && arr[2] > arr[0])
		run(RA, a, NULL);
	else if (arr[0] < arr[1] && arr[1] > arr[2] && arr[2] < arr[0])
	{
		run(SA, a, NULL);
		run(RA, a, NULL);
	}
	else if (arr[0] < arr[1] && arr[1] > arr[2] && arr[2] > arr[0])
		run(RRA, a, NULL);
}

static void	put_top_in_position(t_stack *a, t_stack *b)
{
	int	tb;
	int	_max;
	int	_min;

	tb = b->array[b->top];
	_min = min(a);
	_max = max(a);
	if (tb > _max || tb < _min)
	{
		while (a->array[a->top] != _min)
			run(RA, a, b);
	}
	else
	{
		while (a->array[0] > tb || a->array[a->top] < tb)
			run(RA, a, b);
	}
	run(PA, a, b);
}

static void	sort_tri_complex(t_stack *a, t_stack *b)
{
	run_n(PB, a, b, a->top - 2);
	sort_tri(a);
	while (b->top >= 0)
		put_top_in_position(a, b);
	if (a->array[a->top] > a->top / 2)
	{
		while (a->array[a->top] != 0)
			run(RA, a, b);
	}
}

void	sort_small(t_stack *a, t_stack *b)
{
	if (a->top == 1)
		run(SA, a, NULL);
	else if (a->top == 2)
		sort_tri(a);
	else
		sort_tri_complex(a, b);
}
