/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <aroque@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 19:03:20 by aroque            #+#    #+#             */
/*   Updated: 2021/05/10 10:10:11 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include "general.h"
#include "checker.h"

int	main(int argc, char *argv[])
{
	int		status;
	t_stack	*stack;
	char	**instructions;

	status = 0;
	instructions = NULL;
	stack = get_stack(argc - 1, &argv[1]);
	status = get_instructions(&instructions);
	if (status)
		message_and_exit(stack, instructions, status);
	execute(instructions, stack);
	free_array((void **)instructions);
	free_stack(stack);
	return (status);
}
