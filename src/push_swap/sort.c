/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <aroque@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 21:08:50 by aroque            #+#    #+#             */
/*   Updated: 2021/04/18 17:29:16 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "push_swap.h"
#include "libft.h"
#include "stack.h"
#include "general.h"

#include <stdio.h>

void	sort_mid_point_pull(t_stack *a, t_stack *b, int pivot, int chunk_size)
{
	unsigned int	track;

	track = 0;
	while (chunk_size && b->top > 1)
	{
		if (b->array[b->top] > pivot || chunk_size == 1)
			run(PA, a, b);
		else if (chunk_size <= 2 && b->array[b->top] < b->array[b->top - 1])
		{
			run(SB, a, b);
			run(PA, a, b);
		}
		else if (b->array[b->top] < pivot)
		{
			run(RB, a, b);
			track++;
		}
		//run(RB, a, b);
		//printf("chunk: %d\n", chunk_size);
		//printf("b top: %d\n", b->top);
		//printf("mid: %d\n", mid);
		chunk_size--;
	}
}

void	pull_chunk(t_stack *a, t_stack *b, int chunk_size)
{
	int	mid;
	int	start;

	start = b->top - chunk_size + 1;
	mid = pivot(b->array + start, chunk_size);
	//printf("MID_POINT: %d\nCHUNK_SIZE: %d\n", mid, chunk_size);
	sort_mid_point_pull(a, b, mid, chunk_size);
}

void	sort(t_stack *stack)
{
	t_stack	*new;

	new = initialize(stack->size);
	push_chunk(stack, new);
	free_stack(new);
}
