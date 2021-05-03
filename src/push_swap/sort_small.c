/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <aroque@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 16:52:54 by aroque            #+#    #+#             */
/*   Updated: 2021/05/02 22:29:09 by aroque           ###   ########.fr       */
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

static void	smart_rotate(t_stack *a, int n)
{
	int	find;

	find = a->top;
	while (a->array[find] != n)
		find--;
	if (find < a->top / 2)
		run_n(RRA, a, NULL, find + 1);
	else
		run_n(RA, a, NULL, a->top - find);
}

#include <stdio.h>

static int	closest(t_stack *a, int n)
{
	int k;
	int i;

	if (n > max(a))
		return (min(a));
	i = 0;
	k = max(a);
	while (i <= a->top)
	{
		if (a->array[i] > n && a->array[i] < k)
			k = a->array[i];
		i++;
	}
	return (k);
}

static void	put_top_in_position(t_stack *a, t_stack *b)
{
	int	tb;

	tb = b->array[b->top];
	smart_rotate(a, closest(a, tb));
	run(PA, a, b);
}

static void	sort_tri_complex(t_stack *a, t_stack *b)
{
	run_n(PB, a, b, a->top - 2);
	sort_tri(a);
	while (b->top >= 0)
		put_top_in_position(a, b);
	smart_rotate(a, 0);
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
