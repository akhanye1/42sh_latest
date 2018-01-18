/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmbotho <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/10 10:49:51 by nmbotho           #+#    #+#             */
/*   Updated: 2017/09/10 10:50:29 by nmbotho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h_42sh.h"

void	ft_path_builder(char *addr, char *root, char *filename)
{
	int i;
	int j;

	ft_bzero(addr, PATH_MAX);
	i = -1;
	j = -1;
	while (root[++i])
		addr[i] = root[i];
	addr[i++] = '/';
	while (filename[++j] && ((j + i) <= PATH_MAX))
		addr[j + i] = filename[j];
}

char	*ft_path_builder2(char *root, char *filename)
{
	int		i;
	int		j;
	char	*new;

	new = ft_strnew(ft_strlen(root) + ft_strlen(filename) + 1);
	i = -1;
	j = -1;
	while (root[++i])
		new[i] = root[i];
	if (root[i - 1] != '/')
		new[i++] = '/';
	while (filename[++j])
		new[j + i] = filename[j];
	new[j + i] = '\0';
	return (new);
}

void	ft_change_dir(char *dir)
{
	char *old_pwd;

	if (ft_getenv("PWD"))
		old_pwd = ft_strdup(ft_getenv("PWD"));
	else
		old_pwd = ft_strdup("");
	if (chdir(dir) == 0)
	{
		ft_setenv("PWD", dir);
		ft_setenv("OLDPWD", old_pwd);
	}
	else
		ft_cmderror("no such file or directory", dir);
}

char	*decrement_path(char *path)
{
	int i;

	i = ft_strlen(path) - 1;
	if (i > 0)
	{
		while (path[i] != '/')
		{
			path[i] = '\0';
			i--;
		}
		if (i > 0)
			path[i] = '\0';
	}
	return (path);
}

void	ft_cd(char **args)
{
	char *dir;

	dir = NULL;
	if (args[1])
	{
		if (args[1][0] == '~')
			dir = tidle_handler(args[1]);
		else if (args[1][0] == '-')
			dir = dash_handler(args[1]);
		else if (args[1][0] == '.')
			dir = dot_handler(args[1]);
		else
			dir = basic_handler(args[1]);
		ft_change_dir(dir);
	}
	else if (ft_getenv("HOME"))
		ft_change_dir(ft_strdup(ft_getenv("HOME")));
	else
		ft_change_dir(ft_strdup(""));
}
