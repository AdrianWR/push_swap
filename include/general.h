/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <aroque@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 21:00:27 by aroque            #+#    #+#             */
/*   Updated: 2021/04/11 15:56:30 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

# define SPACE ' '

bool	atoiv(const char *str, int *overflow);
void	free_array(void **array);
void	free_stack(t_stack *stack);
void	message_and_exit(t_stack *stack, char **ops, int status);
t_stack *get_stack(int size, char **args);
