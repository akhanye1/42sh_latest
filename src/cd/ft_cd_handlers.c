/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd_handlers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmbotho <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 18:14:01 by nmbotho           #+#    #+#             */
/*   Updated: 2017/09/30 18:14:05 by nmbotho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h_42sh.h"

char	*tidle_handler(char *dir)
{
	char	*root;

	root = ft_getenv("HOME");
	if (dir[1] == '\0')
		return (ft_strdup(root));
	else if (dir[1] == '/')
		return (ft_strjoin(root, dir + 1));
	else
		return (ft_strdup(dir));
}

char	*dash_handler(char *arg)
{
	char *root;

	root = ft_getenv("HOME");
	if (arg[1] == '-' && arg[2] == '\0')
	{
		if (root)
			return (ft_strdup(root - 1));
		else
			return (ft_strdup(""));
	}
	else if (arg[1] == '\0')
	{
		ft_putendl(ft_getenv("OLDPWD"));
		if (ft_getenv("OLDPWD"))
			return (ft_strdup(ft_getenv("OLDPWD")));
		else
			return (ft_strdup(""));
	}
	else
		return (arg);
}

char	*dot_handler(char *dir)
{
	char	cwd[4096];
	int		i;
	int		dots;

	i = 0;
	dots = 0;
	ft_bzero(cwd, 4096);
	ft_strncpy(cwd, ft_getenv("PWD"), 4096);
	if (dir[i] == '\0')
		return (ft_strdup(cwd));
	while (dir[i] && dots <= 2)
	{
		if (dir[i] == '.')
			dots++;
		else if (dir[i] == '/')
			dots = 0;
		else
			return (ft_path_builder2(cwd, dir + i));
		if (dots == 2)
			decrement_path(cwd);
		i++;
	}
	if (dots > 2)
		return (ft_strdup(dir));
	return (ft_strdup(cwd));
}

char	*basic_handler(char *dir)
{
	char *cwd;

	cwd = ft_getenv("PWD");
	if (!cwd)
		cwd = "";
	if (dir[0] == '/')
		return (ft_strdup(dir));
	else
		return (ft_path_builder2(cwd, dir));
}
