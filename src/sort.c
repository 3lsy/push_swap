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

static void	init_info(void)
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


	printf("===============================\n");
	printf("size:         %d\n", ft_ps()->n_numbers);
	printf("n partitions: %d\n", n_partitions);
	printf("middle:       %d\n", middle);
	printf("offset:       %d\n", offset);
	printf("inset:        %d\n", ft_ps()->info.inset);
	printf("outset:       %d\n", middle + offset);
	printf("===============================\n");
}

void	a2b(void)
{
	int	top;
	int	px;

	while (ft_ps()->a.stack != NULL)
	{
		top = *(int *)ft_ps()->a.stack->obj;
		px = is_between(ft_ps()->info.inset, ft_ps()->info.outset, top);
		printf("  {%d , %d : inset (%d) outset (%d) offset(%d)}\n", top, px, ft_ps()->info.inset, ft_ps()->info.outset, ft_ps()->info.offset);
		if (px >= 0)
		{
			push('B');
			ft_ps()->sorted[px].exists = 0;
			px = is_between(ft_ps()->info.inset, ft_ps()->info.middle - 1, top);
			if (px >= 0)
			{
				rotate('B');
				tweak_offset('i');
			}
			else
				tweak_offset('o');
		}
		else
			rotate('A');
		ft_display_array(ft_ps()->sorted, ft_ps()->n_numbers);
	}
}

void	b2a(void)
{
	while (ft_ps()->b.stack != NULL || ft_ps()->a.tail != 0)
	{

	}
}

void	ft_sort(void)
{
	ft_sort_t_int(ft_ps()->sorted, ft_ps()->n_numbers);
	init_info();
	ft_display_array(ft_ps()->sorted, ft_ps()->n_numbers);
	a2b();
	ft_putstr_fd("Stack A: ", 1);
	ft_display_doubly(ft_ps()->a.stack);
	ft_putstr_fd("\nStack B: ", 1);
	ft_display_doubly(ft_ps()->b.stack);
}
