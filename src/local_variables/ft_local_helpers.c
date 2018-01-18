/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_local_helpers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmbotho <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 17:59:27 by nmbotho           #+#    #+#             */
/*   Updated: 2017/09/30 17:59:32 by nmbotho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h_42sh.h"

char	**ft_get_locals(void)
{
	static char	**variables = NULL;
	int			i;

	i = 0;
	if (!variables)
		variables = (char**)malloc(sizeof(char *) * 4096);
	return (variables);
}

int		ft_keylen(char *pair)
{
	int i;

	i = 0;
	if (pair)
	{
		while (pair[i])
		{
			if (pair[i] == '=')
				return (i);
			i++;
		}
	}
	return (-1);
}

void	ft_print_locals(void)
{
	char	**locals;
	int		i;

	locals = ft_get_locals();
	i = 0;
	while (locals[i])
	{
		ft_putendl(locals[i]);
		i++;
	}
}
