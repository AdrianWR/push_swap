/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <aroque@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 21:09:58 by aroque            #+#    #+#             */
/*   Updated: 2021/05/01 11:52:52 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "stack.h"

# define SA "sa"
# define SB "sb"
# define PA "pa"
# define PB "pb"
# define RA "ra"
# define RB "rb"
# define RRA "rra"
# define RRB "rrb"

int		pivot(int *chunk, size_t size);
void	sort(t_stack *stack);
void	run(char *op, t_stack *a, t_stack *b);
void	run_n(char *op, t_stack *a, t_stack *b, int n);
void	push_chunk(t_stack *a, t_stack *b);
void	pull_chunk(t_stack *a, t_stack *b, int size);
void	push_closest(int p, t_stack *a, t_stack *b);
void	index_stack(t_stack **stack);

#endif
