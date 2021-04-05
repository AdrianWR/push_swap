/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <aroque@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 23:23:49 by aroque            #+#    #+#             */
/*   Updated: 2021/04/04 12:33:55 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# define INSTRUCTIONS_BUFFER_SIZE 16
# include "stack.h"

int	binary_search(int n, int *data, int size);
int	fill_stack(t_stack *stack, char *argv[]);
int	get_instructions(char ***instructions);
int	execute(char **instructions, t_stack *stack);

#endif
