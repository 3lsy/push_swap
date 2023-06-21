/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   limits.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echavez- <echavez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 22:45:57 by echavez-          #+#    #+#             */
/*   Updated: 2023/06/21 18:10:38 by echavez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// pair.x is position
// pair.y is value
static int	find_max(void)
{
	int			i;
	t_pair		max;
	t_doubly	*tmp;

	i = 0;
	tmp = ft_ps()->a.stack;
	max.x = 0;
	max.y = *(int *)tmp->obj;
	tmp = tmp->next;
	while (tmp != ft_ps()->a.stack)
	{
		i++;
		if (*(int *)tmp->obj > max.y)
		{
			max.x = i;
			max.y = *(int *)tmp->obj;
		}
		tmp = tmp->next;
	}
	return (max.x);
}

// pair.x is position
// pair.y is value
static int	find_min(void)
{
	int			i;
	t_pair		min;
	t_doubly	*tmp;

	i = 0;
	tmp = ft_ps()->a.stack;
	min.x = 0;
	min.y = *(int *)tmp->obj;
	tmp = tmp->next;
	while (tmp != ft_ps()->a.stack)
	{
		i++;
		if (*(int *)tmp->obj < min.y)
		{
			min.x = i;
			min.y = *(int *)tmp->obj;
		}
		tmp = tmp->next;
	}
	return (min.x);
}

// pair.x weight
// pair.y max or min {1, -1}
t_pair	find_limit(t_bool search_max, t_bool search_min, int n_numbers)
{
	static int	weight[5] = {0, 1, 2, -2, -1};
	int			max;
	int			min;

	if (n_numbers == 4)
		weight[3] = -1;
	if (search_max)
		max = find_max();
	if (search_min)
		min = find_min();
	if (!search_min)
		return ((t_pair){weight[max], 1});
	else if (!search_max)
		return ((t_pair){weight[min], -1});
	else if (search_max && search_min)
	{
		if (ft_abs(weight[max]) < ft_abs(weight[min]))
			return ((t_pair){weight[max], 1});
		return ((t_pair){weight[min], -1});
	}
	exit_error();
	return ((t_pair){404, 404});
}
