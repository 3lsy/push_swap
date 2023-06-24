/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echavez- <echavez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 18:29:48 by echavez-          #+#    #+#             */
/*   Updated: 2023/06/24 14:05:47 by echavez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** if op == NULL is a push
*/

static t_doubly	**choose_stack(char s, void (*op)(char))
{
	t_doubly	**stack;

	if (op == NULL)
	{
		if (s == 'A')
		{
			ft_ps()->a.size++;
			ft_ps()->b.size--;
		}
		else
		{
			ft_ps()->a.size--;
			ft_ps()->b.size++;
		}
	}
	stack = &ft_ps()->a.stack;
	if (s == 'B')
		stack = &ft_ps()->b.stack;
	else if (op != NULL && s == 'X')
		op('B');
	return (stack);
}

/*
** Param 1 (char) 'A' | 'B' | 'X':
** 'A' == sa
** 'B' == sb
** 'X' == ss
*/

void	swap(char s)
{
	t_doubly	**stack;
	t_doubly	*start;
	t_doubly	*second;

	stack = choose_stack(s, swap);
	if (*stack == NULL || *stack == (*stack)->next)
		return ;
	start = *stack;
	second = start->next;
	if (*stack != (*stack)->next->next)
	{
		start->next = second->next;
		second->next = start;
		second->prev = start->prev;
		start->prev = second;
		second->prev->next = second;
		start->next->prev = start;
	}
	*stack = second;
	ft_push_op(s, "sa", "sb", "ss");
}

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

	stack_in = choose_stack(s, NULL);
	stack_out = &ft_ps()->a.stack;
	if (s == 'A')
		stack_out = &ft_ps()->b.stack;
	if (*stack_out == NULL)
		return ;
	next = (*stack_out)->next;
	prev = (*stack_out)->prev;
	ft_push_doubly(*stack_out, stack_in);
	ft_push_op(s, "pa", "pb", NULL);
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

	stack = choose_stack(s, rotate);
	if (*stack == NULL || *stack == (*stack)->next)
		return ;
	*stack = (*stack)->next;
	ft_push_op(s, "ra", "rb", "rr");
}

/*
** Param 1 (char) 'A' | 'B' | 'X':
** 'A' == rra
** 'B' == rrb
** 'X' == rrr
*/

void	rrotate(char s)
{
	t_doubly	**stack;

	stack = choose_stack(s, rrotate);
	if (*stack == NULL || *stack == (*stack)->prev)
		return ;
	*stack = (*stack)->prev;
	ft_push_op(s, "rra", "rrb", "rrr");
}
