/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echavez- <echavez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 19:08:42 by echavez-          #+#    #+#             */
/*   Updated: 2023/03/08 23:30:27 by echavez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_doubly	*ft_fill_stack()
{
	int			i;
	int			tmp;
	t_doubly	*new;
	t_doubly	*start;
	char		**vargs;

	vargs = ft_ps()->vargs;
	start = NULL;
	i = 0;
	while (vargs[i])
	{
		tmp = ft_atoi(vargs[i]);
		new = ft_new_doubly(&tmp, sizeof(int));
		if (!new)
			return (NULL);
		ft_append_doubly(new, &start);
		i++;
	}
	return (start);
}
