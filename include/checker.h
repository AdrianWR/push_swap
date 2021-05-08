/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <aroque@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 23:23:49 by aroque            #+#    #+#             */
/*   Updated: 2021/05/04 23:40:11 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "stack.h"

# define INSTRUCTIONS_BUFFER_SIZE 4096

int	binary_search(int n, int *data, int size);
int	get_instructions(char ***instructions);
int	execute(char **instructions, t_stack *stack);

#endif
