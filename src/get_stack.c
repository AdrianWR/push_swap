/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <aroque@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 23:27:40 by aroque            #+#    #+#             */
/*   Updated: 2021/04/11 16:16:48 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdbool.h>
#include "stack.h"
#include "libft.h"
#include "checker.h"
#include "general.h"

bool	validate_int(char *elem)
{
	bool			is_int;
	unsigned int	i;
	unsigned int	cm;

	i = 0;
	cm = 0;
	is_int = true;
	while (elem[i] && is_int)
	{
		if (elem[i] == '-' && cm < 1)
			cm++;
		else if (!ft_isdigit(elem[i++]))
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
	bool		exists;

	exists = false;
	if (!data)
		data = malloc(stack_size * sizeof(*data));
	exists = binary_search(n, data, size);
	if (!exists)
		insert_sorted(n, data, size++);
	if (exists || size == stack_size)
		free(data);
	return (exists);
}

int	fill_element(t_stack *stack, char *arg)
{
	unsigned int	j;
	int				n;
	int				status;
	char			**array;

	j = 0;
	status = 0;
	array = ft_split(arg, SPACE);
	while (array[j] && !status)
	{
		if (validate_int(array[j]))
			status = 1;
		if (atoiv(array[j], &n))
			status = 2;
		if (already_exists(n, stack->size))
			status = 3;
		stack->array[++stack->top] = n;
		j++;
	}
	free_array((void **)array);
	return (status);
}

t_stack	*get_stack(int size, char **args)
{
	unsigned int	i;
	int				status;
	t_stack			*stack;

	if (size < 1)
		exit(0);
	i = 0;
	status = 0;
	stack = initialize(size);
	while (args[i] && !status)
		status = fill_element(stack, args[i++]);
	if (status)
	{
		free_stack(stack);
		ft_putstr_fd("Error\n", STDERR_FILENO);
		exit(status);
	}
	return (stack);
}
