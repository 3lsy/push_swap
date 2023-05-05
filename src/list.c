/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echavez- <echavez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 19:08:42 by echavez-          #+#    #+#             */
/*   Updated: 2023/03/17 21:04:46 by echavez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Fill stack A and sorted array
*/

void	ft_fill_stack(void)
{
	int			i;
	int			tmp;
	t_doubly	*new;
	char		**vargs;

	vargs = ft_ps()->vargs;
	i = 0;
	while (vargs[i])
	{
		tmp = ft_atoi(vargs[i]);
		ft_ps()->sorted[i].x = tmp;
		ft_ps()->sorted[i].exists = 1;
		new = ft_new_doubly((void *)&tmp, sizeof(int));
		if (!new)
			exit_error();
		ft_append_doubly(new, &(ft_ps()->a.stack));
		i++;
	}
}

/*
** Do not send mallocated char *operation
*/

void	ft_push_operation(char *operation)
{
	t_doubly	*new;

	new = ft_new_doubly(operation, sizeof(char) * (ft_strlen(operation) + 1));
	if (!new)
		return ;
	ft_append_doubly(new, &(ft_ps()->op_stack));
}
