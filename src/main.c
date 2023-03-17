/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echavez- <echavez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 18:29:48 by echavez-          #+#    #+#             */
/*   Updated: 2023/03/09 20:12:28 by echavez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_display_doubly(t_doubly *start)/////
{
	t_doubly	*tmp;
	if (!start)
	{
		ft_putstr_fd("Empty list", 2);
		return ;
	}
	tmp = start;
	printf("%d\n", *(int *)(start->obj));
	start = start->next;
	while (start != tmp)
	{
		printf("%d\n", *(int *)(start->obj));
		start = start->next;
	}
}

int	main(int ac, char **av)
{
	if (ac < 2)
		return (EXIT_SUCCESS);
	ft_ps()->vargs = &av[1];
	ft_ps()->va_allocated = (ac == 2);
	if (ac == 2)
		ft_ps()->vargs = ft_split_args(av[1]);
	if (!ft_ps()->vargs || ft_analyzer() == EXIT_FAILURE)
		return (ft_perror("Error\n", EXIT_FAILURE));
	ft_ps()->stack_a = ft_fill_stack();
	if (!ft_ps()->stack_a)
		return (ft_perror("Error\n", EXIT_FAILURE));
	ft_display_doubly(ft_ps()->stack_a);
	return (EXIT_SUCCESS);
}

t_ps	*ft_ps(void)
{
	static t_ps	x;

	return (&x);
}

static __attribute__((constructor)) void	ps_constructor(void)
{
	ft_ps()->stack_a = NULL;
	ft_ps()->stack_b = NULL;
	ft_ps()->vargs = NULL;
	ft_ps()->operations = NULL;
	ft_ps()->va_allocated = 0;
}

static __attribute__((destructor)) void	ps_destructor(void)
{
	ft_deldoubly(&ft_ps()->stack_a);
	ft_deldoubly(&ft_ps()->stack_b);
	ft_deldoubly(&ft_ps()->operations);
	if (ft_ps()->va_allocated)
		ft_free_split(&ft_ps()->vargs);
}
