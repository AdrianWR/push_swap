/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <aroque@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 21:00:27 by aroque            #+#    #+#             */
/*   Updated: 2021/04/24 10:25:04 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GENERAL_H
# define GENERAL_H

# include "stack.h"

# define SPACE ' '

int		abs(int n);
bool	atoiv(const char *str, int *overflow);
void	free_array(void **array);
void	free_stack(t_stack *stack);
void	message_and_exit(t_stack *stack, char **ops, int status);
void	reverse_array(int *array, size_t size);
t_stack	*get_stack(int size, char **args);

#endif
