/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_local_variables.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmbotho <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 13:17:40 by nmbotho           #+#    #+#             */
/*   Updated: 2017/09/19 13:17:42 by nmbotho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h_42sh.h"
#define AT_EQUAL (locals[i][len] == '=')

int		ft_set_local(char *pair)
{
	int		i;
	char	**locals;
	int		keylen;

	i = -1;
	locals = ft_get_locals();
	if (pair && locals && ((keylen = ft_keylen(pair)) > -1))
	{
		while (locals[++i] && i < 4094)
		{
			if (ft_strncmp(pair, locals[i], keylen) == 0)
			{
				ft_strdel(locals + i);
				locals[i] = ft_strdup(pair);
				break ;
			}
		}
		if (!locals[i] && i < 4094)
		{
			locals[i++] = ft_strdup(pair);
			locals[i] = NULL;
		}
		return (1);
	}
	return (0);
}

char	*ft_getlocal(char *key)
{
	int		i;
	int		len;
	char	**locals;

	i = 0;
	locals = ft_get_locals();
	if (locals && key)
	{
		len = ft_strlen(key);
		while (locals[i])
		{
			if ((ft_strncmp(key, locals[i], len) == 0) && AT_EQUAL)
				return (locals[i] + len + 1);
			i++;
		}
	}
	return (NULL);
}

void	ft_unset_local(char *key)
{
	int		i;
	int		len;
	char	**locals;

	i = 0;
	len = ft_strlen(key);
	locals = ft_get_locals();
	if (locals && key)
	{
		while (locals[i])
		{
			if ((ft_strncmp(key, locals[i], len) == 0) && AT_EQUAL)
			{
				ft_remove_elem(locals, i);
				break ;
			}
			i++;
		}
	}
}

int		ft_set_local_main(char **args)
{
	int i;

	i = 0;
	while (args[i] && ft_keylen(args[i]) > -1)
	{
		if (!(ft_set_local(args[i])))
		{
			ft_cmderror("command not found", args[i]);
			return (0);
		}
		i++;
	}
	if (args[i] == NULL)
		return (1);
	else
		return (0);
}

int		ft_unset_local_main(char **args)
{
	int i;

	i = 1;
	if (!args[i])
	{
		ft_error("not enought arguments");
		return (1);
	}
	ft_unset_main(args);
	while (args[i])
	{
		ft_unset_local(args[i]);
		i++;
	}
	return (1);
}
