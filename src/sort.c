/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echavez- <echavez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 18:29:48 by echavez-          #+#    #+#             */
/*   Updated: 2023/03/09 20:12:28 by echavez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	init_info()
{
	int	size;
	int	n_partitions;
	int	middle;
	int	offset;

	size = ft_ps()->n_numbers;
	n_partitions = 18;
	if (size <= 10)
		n_partitions = 5;
	else if (size <= 150)
		n_partitions = 8;
	middle = size / 2;
	offset = size / n_partitions;
	ft_ps()->info.n_partitions = n_partitions;
	ft_ps()->info.sorted_middle = middle;
	ft_ps()->info.offset = offset;
	ft_ps()->info.inset = middle - offset;
	if (size % 2 == 0 && ft_ps()->info.inset > 0)
		ft_ps()->info.inset--;
	ft_ps()->info.outset = middle + offset;


	printf("size: %d\n", ft_ps()->n_numbers);
	printf("n partitions: %d\n", n_partitions);
	printf("middle:       %d\n", middle);
	printf("offset:       %d\n", offset);
	printf("inset:        %d\n", ft_ps()->info.inset);
	printf("outset:       %d\n", middle + offset);
}

void	a2b()
{
	//while (ft_ps()->a.stack != NULL)
	//{
	printf("{%d, %d}\n", inset_outset(*(int *)ft_ps()->a.stack->obj), *(int *)ft_ps()->a.stack->obj);
		//}
}

void	ft_sort()
{
	ft_sort_int(ft_ps()->sorted, ft_ps()->n_numbers);
	init_info();
	ft_display_array(ft_ps()->sorted, ft_ps()->n_numbers);
	a2b();
}
