/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 11:11:42 by aroque            #+#    #+#             */
/*   Updated: 2020/01/24 19:04:56 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*map;

	if (!s)
		return (NULL);
	i = -1;
	if (!(map = malloc((ft_strlen(s) + 1) * sizeof(*map))))
		return (NULL);
	while (++i < ft_strlen(s))
		map[i] = f(i, s[i]);
	map[i] = '\0';
	return (map);
}
