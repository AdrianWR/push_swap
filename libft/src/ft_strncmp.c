/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 20:29:51 by aroque            #+#    #+#             */
/*   Updated: 2021/02/03 22:10:47 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (!n)
		return (0);
	else if ((*s1 != *s2) || !*s1)
		return ((unsigned char)*s1 - (unsigned char)*s2);
	return (ft_strncmp(++s1, ++s2, --n));
}
