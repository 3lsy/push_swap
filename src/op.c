/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echavez- <echavez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 18:29:48 by echavez-          #+#    #+#             */
/*   Updated: 2023/03/09 20:12:28 by echavez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Param 1 (char) 'A' | 'B' | 'X':
** 'A' == sa
** 'B' == sb
** 'X' == ss
*/
/*void	swap(char s)
{
	if (s == 'A')
		pass;
	elif (s == 'B')
		pass;
	elif (s == 'X')
		pass;
}
*/
/*
** Param 1 (char) 'A' | 'B':
** 'A' == pa
** 'B' == pb
*/
void	push(char s)
{
	t_doubly	**stack_in;
	t_doubly	**stack_out;
	t_doubly	*next;
	t_doubly	*prev;

	stack_in = &ft_ps()->a.stack;
	stack_out = &ft_ps()->a.stack;
	if (s == 'A')
		stack_out = &ft_ps()->b.stack;
	else if (s == 'B')
		stack_in = &ft_ps()->b.stack;
	next = (*stack_out)->next;
	prev = (*stack_out)->prev;
	ft_push_doubly(*stack_out, stack_in);
	if (next == *stack_out || prev == *stack_out)
	{
		*stack_out = NULL;
		return ;
	}
	prev->next = next;
	next->prev = prev;
	*stack_out = next;
}

/*
** Param 1 (char) 'A' | 'B' | 'X':
** 'A' == ra
** 'B' == rb
** 'X' == rr
*/

void	rotate(char s)
{
	t_doubly	**stack;

	stack = &ft_ps()->a.stack;
	if (s == 'B')
		stack = &ft_ps()->b.stack;
	else if (s == 'X')
		rotate('B');
	if (*stack == NULL)
		return ;
	*stack = (*stack)->next;
}

/*
** Param 1 (char) 'A' | 'B' | 'X':
** 'A' == rra
** 'B' == rrb
** 'X' == rrr
*/
/*void	rrotate(char s)
{
	if (s == 'A')
		pass;
	elif (s == 'B')
		pass;
	elif (s == 'X')
		pass;
}
*/
