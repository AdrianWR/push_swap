/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 09:55:56 by aroque            #+#    #+#             */
/*   Updated: 2020/01/25 22:23:59 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_digit_counter(int n)
{
	if (!(n / 10))
		return (1);
	else
		return (ft_digit_counter(n / 10) + 1);
}

/*
**	Convert an int to its string
**	representation.
*/

char			*ft_itoa(int n)
{
	unsigned int	nbr;
	size_t			len;
	char			*s;

	len = ft_digit_counter(n);
	if (n < 0)
	{
		nbr = -(unsigned int)n;
		len++;
	}
	else
		nbr = (unsigned int)n;
	if (!(s = malloc((len + 1) * sizeof(*s))))
		return (0);
	s[len] = '\0';
	while (len--)
	{
		s[len] = nbr % 10 + '0';
		nbr = nbr / 10;
	}
	if (n < 0)
		s[0] = '-';
	return (s);
}
