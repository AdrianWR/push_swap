/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smart.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <aroque@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 22:40:51 by aroque            #+#    #+#             */
/*   Updated: 2021/05/08 15:05:02 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "push_swap.h"

/*
** Find the next number greater than n in the
** stack. Returns 'n' if there's no such number;
*/

int	closest_above(t_stack *a, int n)
{
	int k;
	int i;

	if (n > max(a))
		return (n);
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

/*
** Put the number 'n' at the top of the stack,
** in the least amount of moves possible (RRA
** or RA). Do nothing if 'n' isn't on stack;
*/

void	smart_rotate(t_stack *a, int n)
{
	int	find;

	find = a->top;
	while (a->array[find] != n && find >= 0)
		find--;
	if (find < 0)
		return ;
	else if (find < a->top / 2)
		run_n(RRA, a, NULL, find + 1);
	else
		run_n(RA, a, NULL, a->top - find);
}
