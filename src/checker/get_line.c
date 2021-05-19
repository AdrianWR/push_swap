/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <aroque@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 12:26:25 by aroque            #+#    #+#             */
/*   Updated: 2021/05/10 09:45:14 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "checker.h"
#include "libft.h"

static bool	invalid_instruction(char *op)
{
	if (ft_streq(op, "sa"))
		return (false);
	else if (ft_streq(op, "sb"))
		return (false);
	else if (ft_streq(op, "ss"))
		return (false);
	else if (ft_streq(op, "pa"))
		return (false);
	else if (ft_streq(op, "pb"))
		return (false);
	else if (ft_streq(op, "ra"))
		return (false);
	else if (ft_streq(op, "rb"))
		return (false);
	else if (ft_streq(op, "rr"))
		return (false);
	else if (ft_streq(op, "rra"))
		return (false);
	else if (ft_streq(op, "rrb"))
		return (false);
	else if (ft_streq(op, "rrr"))
		return (false);
	return (true);
}

static int	heap_set(char ***instructions, char **buffer, int i)
{
	char			**tmp;
	static size_t	in_size;

	tmp = malloc((in_size + i + 1) * sizeof(*tmp));
	if (!tmp)
		return (1);
	if (in_size)
	{
		ft_memcpy(tmp, *instructions, in_size * sizeof(*tmp));
		free(*instructions);
	}
	ft_memcpy(tmp + in_size, buffer, i * sizeof(*tmp));
	tmp[in_size + i] = NULL;
	in_size += i;
	*instructions = tmp;
	return (0);
}

int	get_instructions(char ***instructions)
{
	int		i;
	int		status;
	char	*buffer[INSTRUCTIONS_BUFFER_SIZE];
	char	*op;

	i = 0;
	status = 0;
	while (!status && (get_next_line(STDIN_FILENO, &op) > 0))
	{
		if (invalid_instruction(op))
			status = 1;
		else
		{
			buffer[i++] = op;
			if (i == INSTRUCTIONS_BUFFER_SIZE)
			{
				heap_set(instructions, buffer, i);
				ft_bzero(buffer, INSTRUCTIONS_BUFFER_SIZE);
				i = 0;
			}
		}
	}
	heap_set(instructions, buffer, i);
	free(op);
	return (status);
}
