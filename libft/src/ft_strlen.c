/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 11:21:14 by aroque            #+#    #+#             */
/*   Updated: 2021/05/19 16:34:53 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Returns the number of characters of
**	nul-terminated string.
*/

size_t	ft_strlen(const char *s)
{
	if (!*s)
		return (0);
	return (ft_strlen(s + 1) + 1);
}
