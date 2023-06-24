/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_exec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echavez- <echavez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 13:37:45 by echavez-          #+#    #+#             */
/*   Updated: 2023/06/24 14:14:15 by echavez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

int	exec_push_swap(char *line)
{
	if (ft_strlen(line) == 2 && !ft_strcmp(line, "sa"))
		swap('A');
	else if (ft_strlen(line) == 2 && !ft_strcmp(line, "sb"))
		swap('B');
	else if (ft_strlen(line) == 2 && !ft_strcmp(line, "ss"))
	{
		swap('A');
		swap('B');
	}
	else if (ft_strlen(line) == 2 && !ft_strcmp(line, "pa"))
		push('A');
	else if (ft_strlen(line) == 2 && !ft_strcmp(line, "pb"))
		push('B');
	else
		return (0);
	return (1);
}

int	exec_rot(char *line)
{
	if (ft_strlen(line) == 2 && !ft_strcmp(line, "ra"))
		rotate('A');
	else if (ft_strlen(line) == 2 && !ft_strcmp(line, "rb"))
		rotate('B');
	else if (ft_strlen(line) == 2 && !ft_strcmp(line, "rr"))
	{
		rotate('A');
		rotate('B');
	}
	else if (ft_strlen(line) == 3 && !ft_strcmp(line, "rra"))
		rrotate('A');
	else if (ft_strlen(line) == 3 && !ft_strcmp(line, "rrb"))
		rrotate('B');
	else if (ft_strlen(line) == 3 && !ft_strcmp(line, "rrr"))
	{
		rrotate('A');
		rrotate('B');
	}
	else
		return (0);
	return (1);
}

void	read_op(void)
{
	char	*line;

	line = ft_get_next_line(0);
	while (line)
	{
		if (!exec_push_swap(line) && !exec_rot(line))
		{
			ft_putendl_fd("Error", 2);
			free(line);
			exit(EXIT_FAILURE);
		}
		free(line);
		line = ft_get_next_line(0);
	}
	if (line)
		free(line);
}
