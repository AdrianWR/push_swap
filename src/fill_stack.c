/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <aroque@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 23:27:40 by aroque            #+#    #+#             */
/*   Updated: 2021/04/04 22:22:57 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "stack.h"
#include "libft.h"
#include "checker.h"

bool	validate_int(char **argv)
{
	bool			is_int;
	unsigned int	i;
	char			*elem;

	i = 0;
	is_int = true;
	while (*argv)
	{
		elem = *argv;
		while (elem[i] && is_int)
		{
			if (!ft_isdigit(elem[i]))
				is_int = false;
			i++;
		}
		argv++;
	}
	return (!is_int);
}

void	insert_sorted(int n, int *data, int size)
{
	int	i;

	i = size - 1;
	while (i >= 0 && data[i] > n)
	{
		data[i + 1] = data[i];
		i--;
	}
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
	if (size == stack_size - 1)
		free(data);
	return (false);
}

int	fill_element(t_stack *stack, char *elem)
{
	int	n;

	n = atoi(elem);
	if (already_exists(n, stack->size))
		return (1);
	stack->array[++stack->top] = n;
	return (0);
}

int	fill_stack(t_stack *stack, char *argv[])
{
	int				status;
	unsigned int	i;

	i = 0;
	status = 0;
	if (validate_int(argv))
		return (1);
	while (argv[i] && !status)
	{
		status = fill_element(stack, argv[i]);
		i++;
	}
	return (status);
}
