/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logical_process.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 17:13:49 by angonyam          #+#    #+#             */
/*   Updated: 2018/01/17 11:06:48 by akhanye          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h_42sh.h"

static int			l_run_command(char **directory, char **arguments,
					int i, char **environment)
{
	char			*temp;
	char			*executable;
	int				val;

	temp = ft_strjoin(directory[i], "/");
	executable = ft_strjoin(temp, arguments[0]);
	free(temp);
	free_2d_array((void**)directory);
	val = execve(executable, arguments, environment);
	free(executable);
	return (1);
}

static int			l_executing(char *path, char **environment, char **argument)
{
	char			**directory;
	DIR				*dp;
	struct dirent	*file;
	int				i;

	directory = ft_strsplit(path, ':');
	i = 0;
	while (directory[++i])
	{
		if (!(dp = opendir(directory[i])))
			continue ;
		while ((file = readdir(dp)))
		{
			if (ft_strcmp(file->d_name, argument[0]) == 0)
			{
				return (l_run_command(directory, argument, i, environment));
			}
		}
		closedir(dp);
	}
	free_2d_array((void**)directory);
	return (-2);
}

static int			get_path(char **args, char **env)
{
	int				i;
	char			**path;
	char			*test;

	i = -1;
	while (env[++i])
	{
		if (ft_strlen(env[i]) == 0)
			continue ;
		path = ft_strsplit(env[i], '=');
		if (ft_strcmp(path[0], "PATH") == 0)
		{
			test = ft_strdup(path[1]);
			free_2d_array((void**)path);
			return (l_executing(test, env, args));
		}
		free_2d_array((void**)path);
	}
	return (-2);
}

char				**argument_passing(char *sec)
{
	char			*first;
	char			**args;

	args = ft_strsplit(sec, ' ');
	if (!args[0])
	{
		first = ft_strjoin(sec, " ");
		args = ft_strsplit(first, ' ');
		free(first);
		return (args);
	}
	return (args);
}

int					process2(char *sec, char **env, int *status)
{
	char			**args;
	pid_t			pid;
	int				ex_stat;

	args = argument_passing(sec);
	pid = fork();
	if (pid == 0)
	{
		if (get_path(args, env) == -2)
			if (execve(args[0], args, env) == -1)
			{
				ft_putstr(args[0]);
				ft_putstr(" : command not found\n");
				free_2d_array((void**)args);
				exit(1);
			}
		exit(1);
	}
	free_2d_array((void**)args);
	waitpid(pid, &pid, 0);
	ex_stat = WEXITSTATUS(pid);
	*status = ex_stat;
	return (ex_stat);
}
