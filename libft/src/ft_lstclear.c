/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 20:18:37 by aroque            #+#    #+#             */
/*   Updated: 2020/09/13 15:27:31 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** This function completely erases a linked
** list t_list with a delete function (*del),
** which deletes the content of the node. The
** head then returns as a NULL pointer.
*/

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	if (!(*lst))
		return ;
	if ((*lst)->next)
		ft_lstclear(&(*lst)->next, del);
	ft_lstdelone(*lst, del);
	*lst = NULL;
}
