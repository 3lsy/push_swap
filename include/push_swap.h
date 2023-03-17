/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echavez- <echavez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 12:06:28 by echavez-          #+#    #+#             */
/*   Updated: 2023/03/17 19:58:18 by echavez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "libft.h"
#include <stdio.h>//////////

typedef struct s_ps {
	t_doubly	*stack_a;
	t_doubly	*stack_b;
	t_doubly	*operations;
	char		**vargs;
	t_bool		va_allocated;
}	t_ps;

int			ft_analyzer(void);
t_doubly	*ft_fill_stack(void);
void		ft_push_operation(char *operation);
t_ps		*ft_ps(void);

#endif
