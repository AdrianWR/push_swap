/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <aroque@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 21:08:50 by aroque            #+#    #+#             */
/*   Updated: 2021/05/02 16:58:29 by aroque           ###   ########.fr       */
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
	sort_mid_point_pull(a, b, mid, chunk_size);
}

void pull(t_stack *a, t_stack *b)
{
	while (b->top != -1)
		run(PA, a, b);
}

void	debug(t_stack *s)
{
	int i;

	i = s->top;
	while (i)
		printf("--- %d ---\n", s->array[i--]);
	printf("--- %d ---\n", s->array[i]);
}


void	sort_complex(t_stack *a, t_stack *b)
{
	push_chunk(a, b);
	pull(a, b);
}

void	sort(t_stack *stack)
{
	t_stack	*new;

	if (is_sorted(stack) || stack->top <= 0)
		return ;
	new = initialize(stack->size);
	index_stack(&stack);
	if (stack->top < 5)
		sort_small(stack, new);
	else
		sort_complex(stack, new);
	free_stack(new);
}
