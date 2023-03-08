/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echavez- <echavez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 19:08:42 by echavez-          #+#    #+#             */
/*   Updated: 2023/03/08 19:28:10 by echavez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_doubly	*ft_fill_stack(char **argvs)
{
	int			i;
	int			tmp;
	t_doubly	*new;
	t_doubly	*start;

	start = NULL;
	i = 0;
	while (argvs[i])
	{
		tmp = ft_atoi(argvs[i]);
		new = ft_create_node(&tmp, sizeof(int));
		if (!new)
			return (NULL);
		ft_insert_last(new, &start);
		i++;
	}
	return (start);
}
