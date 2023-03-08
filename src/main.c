/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echavez- <echavez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 18:29:48 by echavez-          #+#    #+#             */
/*   Updated: 2023/03/08 19:36:26 by echavez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_perror(char *e, int n)
{
	ft_putstr_fd(e, 2);
	return (n);
}

void	ft_display_doubly(t_doubly *start)
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
	t_byte		va_allocated;
	char		**vargs;
	t_doubly	*start;

	if (ac < 2)
		return (EXIT_SUCCESS);
	vargs = &av[1];
	va_allocated = (ac == 2);
	if (ac == 2)
		vargs = ft_split_args(av[1]);
	if (!vargs || ft_analyzer(vargs) == EXIT_FAILURE)
	{
		if (va_allocated)
			ft_free_split(&vargs);
		return (ft_perror("Error\n", EXIT_FAILURE));
	}
	start = ft_fill_stack(vargs);
	if (!start)
		return (ft_perror("Error\n", EXIT_FAILURE));
	ft_display_doubly(start);
	return (EXIT_SUCCESS);
}
