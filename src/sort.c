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
	ft_ps()->info.outset = middle + offset - 1;

	if (getenv("PS_VERBOSE") != NULL)
	{
		printf("===============================\n");
		printf("size:         %d\n", ft_ps()->n_numbers);
		printf("n partitions: %d\n", n_partitions);
		printf("middle:       %d\n", middle);
		printf("offset:       %d\n", offset);
		printf("inset:        %d\n", ft_ps()->info.inset);
		printf("outset:       %d\n", middle + offset);
		printf("===============================\n");
	}
}

void	a2b(void)
{
	int	top;
	int	px;

	while (ft_ps()->a.stack != NULL)
	{
		top = *(int *)ft_ps()->a.stack->obj;
		px = is_between(ft_ps()->info.inset, ft_ps()->info.outset, top);
		if (getenv("PS_VERBOSE") != NULL)
			printf("          {%d , %d : inset (%d) outset (%d) offset(%d)}\n", top, px, ft_ps()->info.inset, ft_ps()->info.outset, ft_ps()->info.offset);
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
		if (getenv("PS_VERBOSE") != NULL)
			ft_display_array(ft_ps()->sorted, ft_ps()->n_numbers);
	}
}

void	b2a(void)
{
	t_pair	max;
	ft_ps()->b.head = ft_ps()->info.offset;
	ft_ps()->b.tail = 0;
	ft_ps()->a.tail = 0;
	while (ft_ps()->b.stack != NULL || ft_ps()->a.tail != 0)
	{
		max = max_next();
		if (max.x == 1 && max.y == 0) //First element of B
		{
			push('A');
			ft_ps()->b.head--;
		}
		else if (max.x == 3 && max.y == -1) //Last element of A
		{
			rrotate('A');
			ft_ps()->a.tail--;
		}
		else if (ft_ps()->a.tail == 0 ||
				 (ft_ps()->a.tail > 0 && ft_ps()->b.head > 0
				  && (*(int *)(ft_ps()->b.stack->obj) >
					  *(int *)(ft_ps()->a.stack->prev->obj))))
			// OR FIRST ELEMENT OF B > LAST ELEMENT OF A
		{
			push('A');
			rotate('A');
			ft_ps()->a.tail++;
		}
		else if (max.x == 1) //max is in b head
		{
			rotate('B');
			ft_ps()->b.head--;
		}
		else if (max.x == 2) // max is in b tail
		{
			rrotate('B');
			ft_ps()->b.tail--;
		}
		else
			exit(1);///////// error
	}
}

void	ft_sort(void)
{
	ft_sort_t_int(ft_ps()->sorted, ft_ps()->n_numbers);
	init_info();
	if (getenv("PS_VERBOSE") != NULL)
	{
		ft_display_doubly(ft_ps()->a.stack);
		ft_display_array(ft_ps()->sorted, ft_ps()->n_numbers);
	}
	a2b();
	if (getenv("PS_VERBOSE") != NULL)
	{
		ft_putstr_fd("Stack A: ", 1);
		ft_display_doubly(ft_ps()->a.stack);
		ft_putstr_fd("\nStack B: ", 1);
		ft_display_doubly(ft_ps()->b.stack);
		ft_display_op(ft_ps()->op_stack);
	}
	b2a();
}
