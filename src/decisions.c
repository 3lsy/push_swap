/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decisions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echavez- <echavez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 18:29:48 by echavez-          #+#    #+#             */
/*   Updated: 2023/03/09 20:12:28 by echavez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bool inset_outset(int nb)
{
	int	i;
	int	size;
	int	outset;

	size = ft_ps()->n_numbers;
	outset = ft_ps()->info.outset;
	i = ft_ps()->info.inset;
	while (i < size && i <= outset)
	{
		if (nb == ft_ps()->sorted[i])
			return (1);
		i++;
	}
	return (0);
}
