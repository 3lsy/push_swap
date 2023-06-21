/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echavez- <echavez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 18:29:48 by echavez-          #+#    #+#             */
/*   Updated: 2023/06/21 21:24:16 by echavez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Output:
** Pair values:
**   (x = Max Value, y = Index)
** Return Error:
**	t_pair (-1, -1)
*/

t_pair	max_head(t_doubly *tmp, t_doubly *start)
{
	t_pair		pair;
	int			i;
	int			max;

	if (tmp == NULL || ft_ps()->b.head == 0)
		return ((t_pair){-1, -1});
	i = 0;
	pair.y = i;
	max = *(int *)(tmp->obj);
	i++;
	tmp = tmp->next;
	while (tmp != start && i < ft_ps()->b.head)
	{
		if (max < *(int *)(tmp->obj))
		{
			max = *(int *)(tmp->obj);
			pair.y = i;
		}
		i++;
		tmp = tmp->next;
	}
	pair.x = max;
	return (pair);
}

/*
** Output:
** Pair values:
**   (x = Max Value, y = Index)
** Return Error:
**	t_pair (-1, -1)
*/

t_pair	max_tail(t_doubly *tmp, int tail, int last_index)
{
	t_doubly	*end;
	t_pair		pair;
	int			max;

	if (tmp == NULL || tail == 0)
		return ((t_pair){-1, -1});
	tmp = tmp->prev;
	end = tmp;
	pair.y = last_index;
	max = *(int *)(tmp->obj);
	last_index--;
	tail--;
	tmp = tmp->prev;
	while (tmp != end && tail > 0)
	{
		if (max < *(int *)(tmp->obj))
		{
			max = *(int *)(tmp->obj);
			pair.y = last_index;
		}
		last_index--;
		tail--;
		tmp = tmp->prev;
	}
	return ((t_pair){max, pair.y});
}

/*
** Output:
**   (1) B head
**   (2) B tail
**   (3) A tail
** Pair values:
**   (x = Location, y = Index)
** Return Error:
**	t_pair (-1, -1)
*/

t_pair	max_next(void)
{
	t_pair	bhead;
	t_pair	btail;
	t_pair	atail;

	bhead = max_head(ft_ps()->b.stack, ft_ps()->b.stack);
	btail = max_tail(ft_ps()->b.stack, ft_ps()->b.tail, ft_ps()->b.size - 1);
	atail = max_tail(ft_ps()->a.stack, ft_ps()->a.tail, ft_ps()->a.size - 1);
	if (bhead.y != -1
		&& (btail.y == -1 || bhead.x > btail.x)
		&& (atail.y == -1 || bhead.x > atail.x))
		return ((t_pair){1, bhead.y});
	if (btail.y != -1
		&& (bhead.y == -1 || btail.x > bhead.x)
		&& (atail.y == -1 || btail.x > atail.x))
		return ((t_pair){2, btail.y});
	if (atail.y != -1
		&& (bhead.y == -1 || atail.x > bhead.x)
		&& (btail.y == -1 || atail.x > btail.x))
		return ((t_pair){3, atail.y});
	return ((t_pair){-1, -1});
}
