/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfirst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 17:42:24 by aroque            #+#    #+#             */
/*   Updated: 2020/08/16 17:49:30 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Returns the first element
**	of the linked list lst.
*/

t_list	*ft_lstfirst(t_list *lst)
{
	if (!lst)
		return (NULL);
	else if (!(lst->previous))
		return (lst);
	return (ft_lstfirst(lst->previous));
}
