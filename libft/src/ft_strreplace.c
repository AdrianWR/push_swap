/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strreplace.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <aroque@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 16:40:32 by aroque            #+#    #+#             */
/*   Updated: 2021/05/19 16:33:08 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	replace_s(char **newstr, char *p, const char *r, size_t slen)
{
	char	*old;
	size_t	olen;
	size_t	rlen;

	old = *newstr;
	olen = ft_strlen(old);
	rlen = ft_strlen(r);
	*newstr = malloc((olen - slen + rlen + 1) * sizeof(*newstr));
	if (*newstr == NULL)
	{
		free(old);
		return ;
	}
	ft_memcpy(*newstr, old, p - old);
	ft_memcpy(*newstr + (p - old), r, rlen);
	ft_memcpy(*newstr + (p - old) + rlen, p + slen, olen - slen - (p - old));
	ft_memset(*newstr + olen - slen + rlen, 0, 1);
	free(old);
}

char	*ft_strreplace(char **s, const char *search, const char *replace)
{
	char	*p;
	char	*newstr;
	size_t	search_len;
	size_t	replace_len;

	if (!search || !replace)
		return (*s);
	newstr = ft_strdup(*s);
	search_len = ft_strlen(search);
	replace_len = ft_strlen(replace);
	p = ft_strnstr(newstr, search, ft_strlen(newstr));
	while (p)
	{
		p = ft_strnstr(newstr, search, ft_strlen(newstr));
		replace_s(&newstr, p, replace, search_len);
	}
	free(*s);
	*s = newstr;
	return (*s);
}
