/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <aroque@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 21:00:27 by aroque            #+#    #+#             */
/*   Updated: 2021/04/06 21:02:38 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	free_array(void **array);
void	free_stack(t_stack *stack);
void	message_and_exit(t_stack *stack, char **ops, int status);
int		fill_stack(t_stack *stack, char *argv[]);
