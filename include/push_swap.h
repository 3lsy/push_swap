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

# include "TEMPORARY_INCLUDE.h"//////////
# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

typedef struct s_stack {
	t_doubly	*stack;
	int			head;
	int			tail;
}	t_stack;

typedef struct s_info {
	int			n_partitions;
	int			sorted_middle;
	int			offset;
	int			inset;
	int			outset;
}	t_info;

typedef struct s_ps {
	int			*sorted;
	int			n_numbers;
	t_info		info;

	t_stack		a;
	t_stack		b;
	t_doubly	*op_stack;

	char		**vargs;
	t_bool		va_allocated;
}	t_ps;

void		ft_sort(void);
void		ft_analyzer(void);
void		ft_fill_stack(void);
void		ft_push_operation(char *operation);
t_ps		*ft_ps(void);
void		exit_error(void);

#endif
