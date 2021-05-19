/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <aroque@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 21:08:50 by aroque            #+#    #+#             */
/*   Updated: 2021/05/19 15:26:43 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "general.h"
#include "push_swap.h"

void	sort(t_stack *stack)
{
	t_stack	*new;

	if (is_sorted(stack) || stack->top <= 0)
		return ;
	new = initialize(stack->size);
	if (stack->top < SORT_COMPLEX_LIMIT)
		sort_small(stack, new);
	else
		sort_complex(stack, new);
	free_stack(new);
}
