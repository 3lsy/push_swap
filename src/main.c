/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echavez- <echavez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 18:29:48 by echavez-          #+#    #+#             */
/*   Updated: 2023/02/25 19:06:14 by echavez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_perror(char *e, int n)
{
	ft_putstr_fd(e, 2);
	return (n);
}

/*
** check if the input is not digit or -
** numbers can't be duplicated
*/

int	main(int ac, char **av)
{
	t_byte	va_allocated;
	char	**vargs;

	va_allocated = 0;
	if (ac >= 2)
	{
		vargs = &av[1];
		if (ac == 2)
		{
			va_allocated = 1;
			vargs = ft_split_args(av[1]);
		}
		if (!vargs || ft_analyzer(vargs) == EXIT_FAILURE)
		{
			if (va_allocated)
				ft_free_split(&vargs);
			return (ft_perror("Error\n", EXIT_FAILURE));
		}
	}
	return (EXIT_SUCCESS);
}
