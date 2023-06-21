/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echavez- <echavez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 18:29:48 by echavez-          #+#    #+#             */
/*   Updated: 2023/06/21 21:49:16 by echavez-         ###   ########.fr       */
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
	ft_ps()->info.outset = middle + offset - 1;
}

void	a2b(void)
{
	int	top;
	int	px;

	while (ft_ps()->a.stack != NULL)
	{
		top = *(int *)ft_ps()->a.stack->obj;
		px = is_between(ft_ps()->info.inset, ft_ps()->info.outset, top);
		if (px >= 0)
		{
			push('B');
			ft_ps()->sorted[px].exists = 0;
			px = is_between(ft_ps()->info.inset, ft_ps()->info.middle - 1, top);
			if (px >= 0)
				rotate('B');
			tweak_offset('i');
			tweak_offset('o');
		}
		else
			rotate('A');
	}
}

void	reset_tail_head(void)
{
	ft_ps()->b.head = ft_ps()->n_numbers;
	ft_ps()->b.tail = 0;
	ft_ps()->a.tail = 0;
}

void	b2a(t_pair max)
{
	while (ft_ps()->b.stack != NULL || ft_ps()->a.tail != 0)
	{
		if (ft_ps()->b.head <= 0 && ft_ps()->b.tail <= 0
			&& ft_ps()->a.tail <= 0)
			reset_tail_head();
		max = max_next();
		if (max.x == 1 && max.y == 0)
			b2a_move(&push, 'A', NULL, &ft_ps()->b.head);
		else if (max.x == 3 && max.y == ft_ps()->a.size - 1)
			b2a_move(&rrotate, 'A', NULL, &ft_ps()->a.tail);
		else if (ft_ps()->a.tail == 0 || (ft_ps()->a.tail > 0
				&& (*(int *)(ft_ps()->b.stack->obj)
				> *(int *)(ft_ps()->a.stack->prev->obj))))
		{
			push('A');
			b2a_move(&rotate, 'A', &ft_ps()->a.tail, &ft_ps()->b.head);
		}
		else if (max.x == 1)
			b2a_move(&rotate, 'B', &ft_ps()->b.tail, &ft_ps()->b.head);
		else if (max.x == 2)
			b2a_move(&rrotate, 'B', &ft_ps()->b.head, &ft_ps()->b.tail);
		else
			break ;
	}
}

void	ft_sort(void)
{
	ft_sort_t_int(ft_ps()->sorted, ft_ps()->n_numbers);
	init_info();
	a2b();
	b2a((t_pair){0, 0});
}
