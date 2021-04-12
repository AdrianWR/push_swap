/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mid.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <aroque@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 22:57:26 by aroque            #+#    #+#             */
/*   Updated: 2021/04/11 22:57:39 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	insertion_sort(int array[], size_t size)
{
	int				i;
	unsigned int	j;
	int				key;

	j = 1;
	while (j < size)
	{
		i = j - 1;
		key = array[j++];
		while (i >= 0 && array[i + 1] < array[i])
		{
			array[i + 1] = array[i];
			array[i--] = key;
		}
	}
}

int	mid_point(int *chunk, size_t size)
{
	int	mid;
	int	*copy;
	int index;

	index = size % 2 ? size / 2  : size / 2;
	copy = malloc(size * sizeof(*copy));
	ft_memcpy(copy, chunk, size * sizeof(*copy));
	insertion_sort(copy, size);
	mid = copy[index];
	free(copy);
	return (mid);
}
