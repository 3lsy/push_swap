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
	int			size;
}	t_stack;

typedef struct s_info {
	int			n_partitions;
	int			middle;
	int			offset;
	int			inset;
	int			outset;
}	t_info;

typedef struct s_ps {
	t_int		*sorted;
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
void		ft_push_op(char s, char *op1, char *op2, char *op3);
t_ps		*ft_ps(void);
void		exit_error(void);
int			is_between(int first, int last, int nb);
t_bool		is_empty(int first, int last);
void		tweak_offset(char io);

/*
** operations
*/

void		push(char s);
void		swap0(char s);
void		rotate(char s);
void		rrotate(char s);

/*
** Search
*/

t_pair		max_next(void);

#endif
