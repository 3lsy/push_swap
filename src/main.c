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
	if (!ft_ps()->vargs)
		return (ft_perror("Error\n", EXIT_FAILURE));
	ft_analyzer();
	ft_ps()->sorted = malloc(sizeof(int) * ft_ps()->n_numbers);
	if (!ft_ps()->sorted)
		return (ft_perror("Error\n", EXIT_FAILURE));
	ft_fill_stack();
	ft_display_doubly(ft_ps()->stack_a);//////////////////////
//	if (ft_sort() == EXIT_FAILURE)
//		return (ft_perror("Error\n", EXIT_FAILURE));
	return (EXIT_SUCCESS);
}

void	exit_error(void)
{
	exit(ft_perror("Error\n", EXIT_FAILURE));
}

t_ps	*ft_ps(void)
{
	static t_ps	x;

	return (&x);
}

static __attribute__((constructor)) void	ps_constructor(void)
{
	ft_ps()->sorted = NULL;
	ft_ps()->vargs = NULL;
	ft_ps()->stack_a = NULL;
	ft_ps()->stack_b = NULL;
	ft_ps()->stack_op = NULL;
	ft_ps()->va_allocated = 0;
	ft_ps()->n_numbers = 0;
}

static __attribute__((destructor)) void	ps_destructor(void)
{
	free(ft_ps()->sorted);
	ft_deldoubly(&ft_ps()->stack_a);
	ft_deldoubly(&ft_ps()->stack_b);
	ft_deldoubly(&ft_ps()->stack_op);
	if (ft_ps()->va_allocated)
		ft_free_split(&ft_ps()->vargs);
}
