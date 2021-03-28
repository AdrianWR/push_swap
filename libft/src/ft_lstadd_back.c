/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 18:39:17 by aroque            #+#    #+#             */
/*   Updated: 2020/08/16 16:43:53 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Push new element to the linked list
** end, without changing its head.
*/

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list *last;

	if (!*lst)
		*lst = new;
	else
	{
		last = ft_lstlast(*lst);
		new->previous = last;
		last->next = new;
	}
}
