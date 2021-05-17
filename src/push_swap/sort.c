/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <aroque@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 21:08:50 by aroque            #+#    #+#             */
/*   Updated: 2021/05/10 14:45:36 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "push_swap.h"
#include "libft.h"
#include "stack.h"
#include "general.h"

#include <stdio.h>

static void	debug(t_stack *s)
{
	int i;

	i = s->top;
	while (i)
		printf("--- %d ---\n", s->array[i--]);
	printf("--- %d ---\n", s->array[i]);
}

void	sort(t_stack *stack)
{
	(void) debug;
	t_stack	*new;

	if (is_sorted(stack) || stack->top <= 0)
		return ;
	new = initialize(stack->size);
	if (stack->top < 5)
		sort_small(stack, new);
	else
		sort_complex(stack, new);
	//debug(stack);
	free_stack(new);
}
