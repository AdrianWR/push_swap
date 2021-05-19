/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <aroque@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 22:25:18 by aroque            #+#    #+#             */
/*   Updated: 2021/05/19 15:44:48 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "general.h"
#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	*stack;

	stack = get_stack(argc - 1, &argv[1]);
	index_stack(&stack);
	sort(stack);
	free_stack(stack);
	return (0);
}
