/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve_redirection_args.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmbotho <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 17:47:01 by nmbotho           #+#    #+#             */
/*   Updated: 2017/09/30 17:47:09 by nmbotho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h_42sh.h"

int		last_is_ampersand(char *arg)
{
	int i;

	i = 0;
	while (arg[i])
	{
		if (arg[i] == '&' && !arg[i + 1])
			return (1);
		i++;
	}
	return (0);
}

void	ft_resolve_redirection_args(char **args)
{
	int		i;
	int		j;
	char	*next;
	char	*temp;

	i = 0;
	j = 0;
	while (args[i])
	{
		next = args[i + 1];
		if (next && last_is_ampersand(args[i]) && ft_strcmp(next, "-") == 0)
		{
			temp = ft_strjoin(args[i], " ");
			ft_strdel(args + i);
			args[i] = ft_strjoin(temp, next);
			ft_strdel(&temp);
			ft_remove_elem(args, i + 1);
			i--;
		}
		i++;
	}
}

void	ft_continue_if_is_var(int *i, int *k, char *cmd, char *new)
{
	if (*i && cmd[*i] == '\"' && cmd[*i - 1] == '=')
	{
		*i = *i + 1;
		while (cmd[*i] && cmd[*i] != '\"')
		{
			new[*k] = cmd[*i];
			(*i)++;
			(*k)++;
		}
	}
}
