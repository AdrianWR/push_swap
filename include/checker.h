/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <aroque@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 23:23:49 by aroque            #+#    #+#             */
/*   Updated: 2021/04/08 08:20:39 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# define INSTRUCTIONS_BUFFER_SIZE 16
# include "stack.h"

int	binary_search(int n, int *data, int size);
int	get_instructions(char ***instructions);
int	execute(char **instructions, t_stack *stack);

#endif
