/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <aroque@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 19:03:20 by aroque            #+#    #+#             */
/*   Updated: 2021/03/28 20:07:07 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include "stack.h"

bool validate_int(char *elem)
{
	bool		is_int;
	unsigned	i;

	i = 0;
	is_int = true;
	while (elem[i] && is_int)
	{
		if (!ft_isdigit(elem[i]))
			is_int = false;
	}
	return (is_int);
}

int binary_search(int n, int *data, int size)
{
	int mid;
	int	left;
	int	right;

	left = 0;
	right = size - 1;
	while (left <= right)
	{
		mid = left + ((right - left) / 2);
		if (data[mid] == n)
			return (true);
		else if (n < data[mid])
			right = mid - 1;
		else
			left = mid + 1;
	}
	return (false);
}

void insert_sorted(int n, int *data, int size)
{
	int i;

	i = size - 1;
	while (i >= 0 && data[i] > n)
	{
		data[i + 1] = data[i];
		i--;
	}
	data[i + 1] = n;
}

bool already_exists(n)
{
	static int	*data; 
	static int	size; 

	if (binary_search(n, data, size))
		return (true);
	insert_sorted(n, data, size++);
	return (false);
}

int	fill_element(t_stack *stack, char *elem)
{
	int	n;

	if (validate_int(elem))
		return (1);
	n = atoi(elem);
	if (already_exists(n))
		return (1);
	stack->array[++stack->top] = n;
	return (0);
}

int	fill_stack(t_stack *stack, char *argv[])
{
	int			status;
	unsigned	i;

	i = 0;
	status = 0;
	while (argv[i] && !status)
		status = fill_element(stack, argv[i]);
	return (status);
}


int	main(int argc, char *argv[])
{
	t_stack *stack;

	if (argc <= 1)
		return (0);
	stack = initialize(argc);
	if (fill_stack(stack, &argv[1]))
		return (1);
	//checker(stack);
	return (0);
}
