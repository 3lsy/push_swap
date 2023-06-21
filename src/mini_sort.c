/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echavez- <echavez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 19:20:13 by echavez-          #+#    #+#             */
/*   Updated: 2023/06/21 13:07:26 by echavez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ret2a(void)
{
	if (ft_ps()->b.stack == NULL)
		return ;
	push('A');
	if (*(int *)ft_ps()->a.stack->obj > *(int *)ft_ps()->a.stack->next->obj)
		rotate('A');
	ret2a();
}

void	sort_three(void)
{
	int	top;
	int	middle;
	int last;

	top = *(int *)ft_ps()->a.stack->obj;
	middle = *(int *)ft_ps()->a.stack->next->obj;
	last = *(int *)ft_ps()->a.stack->prev->obj;
	if (top < middle && middle < last)
	{
		if (ft_ps()->b.stack != NULL)
			ret2a();
		return ;
	}
	else if (middle > top && middle > last)
		rrotate('A');
	else if (top > middle && top > last)
		rotate('A');
	else
		swap('A');
	sort_three();
}

void	sort_five(int limit_max, int limit_min)
{
	t_pair	limit;

	if (ft_ps()->n_numbers == 2 &&
		*(int *)ft_ps()->a.stack->obj > *(int *)ft_ps()->a.stack->next->obj)
			swap('A');
	if (ft_ps()->n_numbers == 3)
		sort_three();
	if (ft_ps()->n_numbers >= 4)
	{
		limit = find_limit(limit_max, limit_min);
		if (limit.x < 0)
			op_repeat(limit.x, rrotate, 'A');
		if (limit.x > 0)
			op_repeat(limit.x, rotate, 'A');
		push('B');
		if (!limit_max || !limit_min || ft_ps()->n_numbers == 4)
			sort_three();
	}
	if (limit_max && limit_min && ft_ps()->n_numbers == 5)
	{
		ft_ps()->n_numbers = 4;
		if (limit.y > 0)
			sort_five(0, 1);
		else
			sort_five(1, 0);
	}
}

void	op_repeat(int i, void (*op)(char), char s)
{
	i = ft_abs(i);
	while (i > 0)
	{
		op(s);
		i--;
	}
}
