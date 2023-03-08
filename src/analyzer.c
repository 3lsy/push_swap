/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyzer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echavez- <echavez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 18:31:59 by echavez-          #+#    #+#             */
/*   Updated: 2023/03/08 23:28:46 by echavez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_lexer_parser(char *arg)
{
	int	i;

	i = 0;
	if (arg[i] == '-')
		i++;
	while (arg[i])
	{
		if (!ft_isdigit(arg[i]))
			return (EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}

static int	ft_semantic(char **vargs, char *arg, int i)
{
	i++;
	while (vargs[i])
	{
		if (!ft_strcmp(vargs[i++], arg))
			return (EXIT_FAILURE);
	}
	if (!ft_isint(arg))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	ft_analyzer(void)
{
	int	i;
	char	**vargs;

	vargs = ft_ps()->vargs;
	i = 0;
	while (vargs[i])
	{
		if (ft_lexer_parser(vargs[i]) == EXIT_FAILURE)
			return (EXIT_FAILURE);
		if (ft_semantic(vargs, vargs[i], i) == EXIT_FAILURE)
			return (EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}
