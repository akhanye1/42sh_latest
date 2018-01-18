/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmbotho <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 13:17:28 by nmbotho           #+#    #+#             */
/*   Updated: 2017/09/19 13:17:31 by nmbotho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h_42sh.h"

int		ft_export_key(char *key)
{
	char **locals;
	char **env;
	char *value;

	locals = ft_get_locals();
	env = ft_get_environ();
	if ((value = ft_getlocal(key)))
	{
		ft_setenv(key, ft_strdup(value));
		return (1);
	}
	return (0);
}

void	ft_export(char **args)
{
	int		i;
	char	**env;

	env = ft_get_environ();
	i = 0;
	if (args[1] == NULL)
		ft_env(env);
	while (args[i])
	{
		if (ft_export_key(args[i]) == 0)
		{
			ft_set_local_main(args + 1);
			ft_setenv_main(args);
		}
		i++;
	}
}
