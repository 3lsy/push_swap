/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decisions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echavez- <echavez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 18:29:48 by echavez-          #+#    #+#             */
/*   Updated: 2023/06/23 12:27:21 by echavez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_between(int first, int last, int nb)
{
	int	i;
	int	size;

	i = first;
	size = ft_ps()->n_numbers;
	while (i < size && i <= last)
	{
		if (nb == ft_ps()->sorted[i].x)
			return (i);
		i++;
	}
	return (-1);
}

t_bool	is_empty(int first, int last)
{
	int	i;
	int	size;

	i = first;
	size = ft_ps()->n_numbers;
	while (i < size && i <= last)
	{
		if (ft_ps()->sorted[i].exists)
			return (0);
		i++;
	}
	return (1);
}

void	tweak_offset(char io)
{
	if (io == 'i')
	{
		if (is_empty(ft_ps()->info.inset, ft_ps()->info.middle))
		{
			ft_ps()->info.inset -= ft_ps()->info.offset;
			if (ft_ps()->info.inset < 0)
				ft_ps()->info.inset = 0;
		}
	}
	else if (io == 'o')
	{
		if (is_empty(ft_ps()->info.middle, ft_ps()->info.outset))
		{
			ft_ps()->info.outset += ft_ps()->info.offset;
			if (ft_ps()->info.outset >= ft_ps()->n_numbers)
				ft_ps()->info.outset = ft_ps()->n_numbers - 1;
		}
	}
}

int	is_sorted(void)
{
	t_doubly	*tmp;
	t_doubly	*next_tmp;

	if (ft_ps()->b.stack != NULL)
		return (0);
	if (ft_ps()->a.stack == NULL
		|| ft_ps()->a.stack == ft_ps()->a.stack->next)
		return (1);
	tmp = ft_ps()->a.stack;
	next_tmp = ft_ps()->a.stack->next;
	while (next_tmp != ft_ps()->a.stack)
	{
		if (*(int *)tmp->obj > *(int *)next_tmp->obj)
			return (0);
		tmp = tmp->next;
		next_tmp = next_tmp->next;
	}
	return (1);
}
