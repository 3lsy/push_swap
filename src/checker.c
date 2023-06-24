/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echavez- <echavez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 12:23:02 by echavez-          #+#    #+#             */
/*   Updated: 2023/06/24 13:59:03 by echavez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

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
	ft_ps()->sorted = malloc(sizeof(t_int) * ft_ps()->n_numbers);
	if (!ft_ps()->sorted)
		return (ft_perror("Error\n", EXIT_FAILURE));
	ft_fill_stack();
	read_op();
	if (is_sorted())
		ft_putendl_fd("OK", 1);
	else
		ft_putendl_fd("KO", 1);
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
	ft_ps()->checker = 1;
	ft_ps()->a.head = 0;
	ft_ps()->a.tail = 0;
	ft_ps()->a.size = 0;
	ft_ps()->a.stack = NULL;
	ft_ps()->b.head = 0;
	ft_ps()->b.tail = 0;
	ft_ps()->b.size = 0;
	ft_ps()->b.stack = NULL;
	ft_ps()->op_stack = NULL;
	ft_ps()->sorted = NULL;
	ft_ps()->vargs = NULL;
	ft_ps()->va_allocated = 0;
	ft_ps()->n_numbers = 0;
	ft_ps()->info.n_partitions = 0;
	ft_ps()->info.middle = 0;
	ft_ps()->info.offset = 0;
	ft_ps()->info.inset = 0;
	ft_ps()->info.outset = 0;
}

static __attribute__((destructor)) void	ps_destructor(void)
{
	free(ft_ps()->sorted);
	ft_deldoubly(&ft_ps()->a.stack);
	ft_deldoubly(&ft_ps()->b.stack);
	ft_deldoubly(&ft_ps()->op_stack);
	if (ft_ps()->va_allocated)
		ft_free_split(&ft_ps()->vargs);
}
