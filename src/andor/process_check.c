/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 17:58:13 by angonyam          #+#    #+#             */
/*   Updated: 2018/01/17 10:27:55 by akhanye          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h_42sh.h"

int					verdict(char *room, char *arg, char **array)
{
	char			*temp;
	char			*file;
	int				ret;

	temp = ft_strjoin(room, "/");
	file = ft_strjoin(temp, arg);
	free(temp);
	ret = access(file, X_OK | F_OK) == -1 ? -1 : 1;
	free(file);
	free_2d_array((void**)array);
	return (ret);
}

int					path_checker(char *path, char *comm)
{
	char			**visit;
	int				i;
	struct dirent	*dir;
	DIR				*dp;
	int				ret;

	visit = ft_strsplit(path, ':');
	i = -1;
	while (visit[++i])
	{
		if (!(dp = opendir(visit[i])))
			continue ;
		while ((dir = readdir(dp)))
		{
			if (ft_strcmp(dir->d_name, comm) == 0)
			{
				ret = verdict(visit[i], comm, visit);
				closedir(dp);
				return (ret);
			}
		}
		closedir(dp);
	}
	free_2d_array((void**)visit);
	return (-1);
}

int					availability(char **env, char *str)
{
	char			**arr;
	int				i;
	int				ret;

	ret = -1;
	i = 0;
	while (env[i])
	{
		arr = ft_strsplit(env[i], '=');
		if (ft_strcmp(arr[0], "PATH") == 0)
		{
			ret = path_checker(arr[1], str);
			free_2d_array((void**)arr);
			return (ret);
		}
		free_2d_array((void**)arr);
		i++;
	}
	return (ret);
}

int					check_accessing(char *str)
{
	char			**two;
	int				ret;

	ret = 0;
	two = ft_strsplit(str, ' ');
	if (two)
	{
		if (access(two[0], F_OK | X_OK) == 0)
		{
			ret = 1;
		}
	}
	else
	{
		if (access(str, F_OK | X_OK) == 0)
			ret = 1;
	}
	free_2d_array((void**)two);
	return (ret);
}

int					process_checker(char **env, char *str)
{
	int				i;
	int				ret;
	char			**two;

	ret = -1;
	i = 0;
	if (check_accessing(str) == 1)
		return (1);
	else
	{
		two = ft_strsplit(str, ' ');
		if (two)
		{
			ret = availability(env, two[0]);
			free_2d_array((void**)two);
		}
		else
			ret = availability(env, str);
	}
	if (ret == -1)
	{
		ft_putstr(str);
		ft_putstr(" : command not found\n");
	}
	return (ret);
}
