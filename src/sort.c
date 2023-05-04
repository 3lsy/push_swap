/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echavez- <echavez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 18:29:48 by echavez-          #+#    #+#             */
/*   Updated: 2023/03/09 20:12:28 by echavez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	init_info()
{
	int	size;
	int	n_partitions;
	int	middle;
	int	offset;

	size = ft_ps()->n_numbers;
	n_partitions = 18;
	if (size <= 10)
		n_partitions = 5;
	else if (size <= 150)
		n_partitions = 8;
	middle = size / 2;
	offset = size / n_partitions;
	if (offset == 0)
		offset = 1;
	ft_ps()->info.n_partitions = n_partitions;
	ft_ps()->info.middle = middle;
	ft_ps()->info.offset = offset;
	ft_ps()->info.inset = middle - offset;
	if (size % 2 == 0 && ft_ps()->info.inset > 0)
		ft_ps()->info.inset--;
	ft_ps()->info.outset = middle + offset;


	printf("size: %d\n", ft_ps()->n_numbers);
	printf("n partitions: %d\n", n_partitions);
	printf("middle:       %d\n", middle);
	printf("offset:       %d\n", offset);
	printf("inset:        %d\n", ft_ps()->info.inset);
	printf("outset:       %d\n", middle + offset);
}

void	a2b()
{
	int	top;
	int	pos;

	while (ft_ps()->a.stack != NULL)
	{
		top = *(int *)ft_ps()->a.stack->obj;
		pos = is_between(ft_ps()->info.inset, ft_ps()->info.outset, top);
		printf("{%d , %d : inset (%d) outset (%d) offset(%d)}\n", top, pos, ft_ps()->info.inset, ft_ps()->info.outset, ft_ps()->info.offset);
		if (pos >= 0)
		{
			push('B');
			printf("push b\n");
			ft_ps()->sorted[pos].exists = 0;
			pos = is_between(ft_ps()->info.inset, ft_ps()->info.middle, top);
			if (pos >= 0 && pos != ft_ps()->info.middle)
			{
				rotate('B');
				printf("rotate b\n");
				tweak_offset('i');
			}
			else
				tweak_offset('o');
			if (pos == ft_ps()->info.middle)
				tweak_offset('i');
		}
		else
		{
			rotate('A');
			printf("rotate a\n");
		}
		ft_display_array(ft_ps()->sorted, ft_ps()->n_numbers);
	}
}

void	ft_sort()
{
	ft_sort_t_int(ft_ps()->sorted, ft_ps()->n_numbers);
	init_info();
	ft_display_array(ft_ps()->sorted, ft_ps()->n_numbers);
	printf("---\n");
	a2b();
	ft_putstr_fd("Stack A: ", 1);
	ft_display_doubly(ft_ps()->a.stack);
	ft_putstr_fd("\nStack B: ", 1);
	ft_display_doubly(ft_ps()->b.stack);
}
