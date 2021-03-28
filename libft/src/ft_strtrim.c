/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 03:55:14 by aroque            #+#    #+#             */
/*   Updated: 2020/01/24 18:53:20 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_charset(char c, char const *set)
{
	if (!*set)
		return (0);
	else if (c == *set)
		return (1);
	else
		return (ft_charset(c, ++set));
}

static int	ft_left_trim(char const *s1, char const *set)
{
	if (!(*s1 && ft_charset(*(char *)s1, set)))
		return (0);
	else
		return (ft_left_trim(++s1, set) + 1);
}

static int	ft_right_trim(char const *s1, char const *set, size_t len)
{
	while (s1[len] && ft_charset(s1[len], set))
		len--;
	return (len + 1);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	char	*trim;
	int		lt;
	int		rt;

	if (!s1 || !set)
		return (NULL);
	lt = ft_left_trim(s1, set);
	rt = ft_right_trim(s1, set, ft_strlen(s1) - 1);
	rt < lt ? rt = lt : rt;
	if (!(trim = malloc((rt - lt + 1) * sizeof(*trim))))
		return (NULL);
	ft_strlcpy(trim, &s1[lt], rt - lt + 1);
	return (trim);
}
