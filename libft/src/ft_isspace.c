/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 23:21:57 by aroque            #+#    #+#             */
/*   Updated: 2020/09/15 11:59:33 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Check if a char is ASCII space, tabulation, carriage return
**  or another space character as defined in isspace(3).
*/

int		ft_isspace(char str)
{
	return (str == 0x20 || (str >= 0x09 && str <= 0x0d));
}
