/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <aroque@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 14:39:45 by aroque            #+#    #+#             */
/*   Updated: 2021/04/04 22:00:47 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

bool	binary_search(int n, int *data, int size)
{
	int	mid;
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
