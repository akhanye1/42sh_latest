/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_helper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmbotho <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 18:09:37 by nmbotho           #+#    #+#             */
/*   Updated: 2017/09/30 18:09:40 by nmbotho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h_42sh.h"

int		contains_equalsign(char *arg)
{
	int i;

	i = 0;
	while (arg && arg[i])
	{
		if (arg[i] == '=')
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_form_variable(char *key, char *value)
{
	char *temp;
	char *variable;

	temp = ft_strjoin(key, "=");
	if (!temp)
		return (NULL);
	if (value)
	{
		variable = ft_strjoin(temp, value);
		ft_strdel(&temp);
		ft_strdel(&value);
		return (variable);
	}
	else
		return (temp);
}

char	**ft_get_environ(void)
{
	extern char **environ;
	static char **env = NULL;
	int			i;

	i = -1;
	if (env == NULL)
	{
		env = (char**)malloc(sizeof(char*) * 4096);
		while (environ[++i])
			env[i] = ft_strdup(environ[i]);
		env[i] = NULL;
	}
	return (env);
}

int		ft_setenv(char *key, char *value)
{
	int		i;
	int		len;
	char	**env;

	i = 0;
	len = ft_strlen(key);
	env = ft_get_environ();
	if (key)
	{
		while (env[i])
		{
			if ((ft_strncmp(key, env[i], len) == 0) && (env[i][len] == '='))
			{
				ft_strdel(env + i);
				env[i] = ft_form_variable(key, value);
				return (1);
			}
			i++;
		}
		env[i++] = ft_form_variable(key, value);
		env[i] = NULL;
		return (1);
	}
	return (0);
}

int		ft_setenv_pair(char *pair)
{
	int		i;
	char	*key;
	int		index;

	i = 0;
	if ((index = ft_keylen(pair)) > -1)
	{
		key = ft_strsub(pair, 0, index);
		ft_setenv(key, pair + index + 1);
		return (1);
	}
	else
		return (0);
}
