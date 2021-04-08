/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <aroque@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 23:27:40 by aroque            #+#    #+#             */
/*   Updated: 2021/04/08 08:41:25 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "stack.h"
#include "libft.h"
#include "checker.h"
#include "general.h"

bool	validate_int(char *elem)
{
	bool			is_int;
	unsigned int	i;

	i = 0;
	is_int = true;
	while (elem[i] && is_int)
	{
		if (!ft_isdigit(elem[i++]))
			is_int = false;
	}
	return (!is_int);
}

void	insert_sorted(int n, int *data, int size)
{
	int	i;

	i = size;
	while (--i >= 0 && data[i] > n)
		data[i + 1] = data[i];
	data[i + 1] = n;
}

bool	already_exists(n, stack_size)
{
	static int	*data;
	static int	size;

	if (!data)
		data = malloc(stack_size * sizeof(*data));
	if (binary_search(n, data, size))
	{
		free(data);
		return (true);
	}
	insert_sorted(n, data, size++);
	if (size == stack_size)
		free(data);
	return (false);
}

int	fill_element(t_stack *stack, char *elem)
{
	int	n;

	if (validate_int(elem))
		return (1);
	n = atoi(elem);
	if (already_exists(n, stack->size))
		return (1);
	stack->array[++stack->top] = n;
	return (0);
}

t_stack	*fill_stack(int size, char **args)
{
	int				status;
	unsigned int	i;
	t_stack			*stack;

	i = 0;
	status = 0;
	stack = initialize(size);
	while (args[i] && !status)
		status = fill_element(stack, args[i++]);
	if (status)
		message_and_exit(stack, NULL, status);
	return (stack);
}
