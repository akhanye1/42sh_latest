/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmbotho <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/05 17:40:28 by nmbotho           #+#    #+#             */
/*   Updated: 2017/09/06 17:25:37 by skgatle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h_42sh.h"
#define LEN ft_strlen(args[i] + (index + 1))

void	ft_unsetenv(char *key)
{
	int		i;
	int		len;
	char	**env;

	i = 0;
	len = ft_strlen(key);
	env = ft_get_environ();
	if (env && key)
	{
		while (env[i])
		{
			if ((ft_strncmp(key, env[i], len) == 0) && (env[i][len] == '='))
			{
				ft_remove_elem(env, i);
				break ;
			}
			i++;
		}
	}
}

char	*ft_getenv(char *key)
{
	int		i;
	int		len;
	char	**env;

	i = 0;
	len = ft_strlen(key);
	env = ft_get_environ();
	if (env && key)
	{
		while (env[i])
		{
			if ((ft_strncmp(key, env[i], len) == 0) && (env[i][len] == '='))
				return (env[i] + len + 1);
			i++;
		}
	}
	return ("");
}

void	ft_setenv_main(char **args)
{
	int		i;
	int		index;
	char	*key;
	char	*value;

	i = 1;
	while (args[i])
	{
		if ((index = contains_equalsign(args[i])) > 0)
		{
			key = ft_strsub(args[i], 0, index);
			value = ft_strsub(args[i], index + 1, LEN);
			ft_setenv(key, value);
			ft_strdel(&key);
		}
		i++;
	}
}

void	ft_unset_main(char **args)
{
	int i;

	i = 1;
	while (args[i])
	{
		ft_unsetenv(args[i]);
		i++;
	}
}

void	ft_env(char **args)
{
	int		i;
	char	**env;

	i = 0;
	if (args[0])
	{
		env = ft_get_environ();
		if (env)
			while (env[i++])
				ft_putendl(env[i]);
	}
}
