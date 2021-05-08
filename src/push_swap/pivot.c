/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mid.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <aroque@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 22:57:26 by aroque            #+#    #+#             */
/*   Updated: 2021/05/01 11:49:35 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "general.h"

int	pivot(int *chunk, size_t size)
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


