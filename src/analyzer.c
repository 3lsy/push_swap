/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyzer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echavez- <echavez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 18:31:59 by echavez-          #+#    #+#             */
/*   Updated: 2023/06/24 13:54:39 by echavez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_lexer_parser(char *arg)
{
	int	i;

	i = 0;
	if (arg[i] == '-')
		i++;
	while (arg[i])
	{
		if (!ft_isdigit(arg[i]))
			exit_error();
		i++;
	}
}

static void	ft_semantic(char **vargs, char *arg, int i)
{
	i++;
	while (vargs[i])
	{
		if (!ft_strcmp(vargs[i++], arg))
			exit_error();
	}
	if (!ft_isint(arg))
		exit_error();
}

void	ft_analyzer(void)
{
	int		i;
	char	**vargs;

	vargs = ft_ps()->vargs;
	i = 0;
	while (vargs[i])
	{
		if (ft_strlen(vargs[i]) == 0)
			exit_error();
		ft_lexer_parser(vargs[i]);
		ft_semantic(vargs, vargs[i], i);
		i++;
	}
	if (i == 0)
		exit_error();
	ft_ps()->n_numbers = i;
	ft_ps()->a.size = i;
}
