/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <aroque@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 21:08:50 by aroque            #+#    #+#             */
/*   Updated: 2021/04/12 22:18:37 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "push_swap.h"
#include "libft.h"
#include "stack.h"
#include "general.h"

#include <stdio.h>

void	sort_mid_point_pull(t_stack *a, t_stack *b, int mid, int chunk_size)
{
	int i;

	i = 0;
	if (chunk_size == 1)
	{
		run(PA, a, b);
		return ;
	}
	while (i < chunk_size && b->top > 1)
	{
		if (b->array[b->top] > mid)
		{
			run(PA, a, b);
			i++;
		}
		else if (b->array[b->top - chunk_size + i] > mid)
		{
			run(RRB, a, b);
			run(PA, a, b);
			i++;
		}
		else
			run(RB, a, b);
		printf("chunk: %d\n", chunk_size);
		printf("b top: %d\n", b->top);
		printf("mid: %d\n", mid);
		printf("i: %d\n", i);
	}
}

void	pull_chunk(t_stack *a, t_stack *b, int chunk_size)
{
	int	mid;
	int	start;

	printf("a top: %d\n", a->top);
	printf("b top: %d\n", b->top);
	start = b->top - chunk_size + 1;
	mid = mid_point(b->array + start, chunk_size);
	printf("MID_POINT: %d\nCHUNK_SIZE: %d\n", mid, chunk_size);
	sort_mid_point_pull(a, b, mid, chunk_size);
}

void	sort(t_stack *stack)
{
	t_stack	*new;

	new = initialize(stack->size);
	push_chunk(stack, new);
	free_stack(new);
}
