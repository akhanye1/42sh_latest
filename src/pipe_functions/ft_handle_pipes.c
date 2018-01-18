/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_pipes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skgatle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/30 15:00:56 by skgatle           #+#    #+#             */
/*   Updated: 2018/01/10 09:37:14 by skgatle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h_42sh.h"

/*
** check for redirects before running all the piped commands
*/

static void	ft_check_redirects(char **p_cmds, t_pipe *info)
{
	char	*file;
	int		fd;

	while (*p_cmds)
	{
		if (!(file = get_target(*p_cmds, " >> ")) &&
			!(file = get_target(*p_cmds, " > ")) &&
			!(file = get_target(*p_cmds, " 1>> ")) &&
			!(file = get_target(*p_cmds, " 1> ")))
			return ;
		if ((ft_strstr(*p_cmds, " >> ") || ft_strstr(*p_cmds, " 1>> "))
				&& APPEND)
			fd = openfile(file, 1);
		else if (ft_strstr(*p_cmds, " > ") || ft_strstr(*p_cmds, " 1> "))
			fd = openfile(file, 0);
		p_cmds = p_cmds + 1;
	}
}

static int	ft_parse_pipes(char **p_pipes)
{
	char *trimmed;

	while (*p_pipes)
	{
		trimmed = ft_strtrim(*p_pipes);
		if (ft_strlen(trimmed) < 2)
		{
			free(trimmed);
			return (0);
		}
		free(trimmed);
		p_pipes = p_pipes + 1;
	}
	return (1);
}

static int	ft_run_pipes(char *args, t_pipe *info)
{
	char **pipe_args;
	char **p_pipes;

	if (!(pipe_args = ft_strsplit(args, '|')))
	{
		ft_cmderror("Failed to allocate memory : ", "malloc");
		return (1);
	}
	p_pipes = pipe_args;
	ft_check_redirects(p_pipes, info);
	info->p_flag = TRUE;
	if (!ft_parse_pipes(p_pipes) || ft_pipe_recursive(pipe_args, 0, info) == -1)
	{
		ft_cmderror("Failed to initialize pipe", "pipe function");
		return (1);
	}
	info->p_flag = FALSE;
	ft_free2d((void **)pipe_args);
	return (1);
}

/*
** Gets arguments (2d array) from ft_split_cmd and runs it through the piping
** or straight to exec function if the is none(no pipes);
*/

int			ft_handle_pipes(char **args)
{
	t_pipe	info;

	canonical_off();
	while (args && *args)
	{
		info.p_last = FALSE;
		info.r_flag = FALSE;
		info.pip_red = FALSE;
		info.append = FALSE;
		info.red_err = FALSE;
		info.p_flag = FALSE;
		info.builtin_act = FALSE;
		info.exit_builtin = FALSE;
		if (ft_strchr(*args, '|'))
			ft_run_pipes(*args, &info);
		else
		{
			backticks_handler(&*args, &info);
			ft_execute_handler(*args, &info);
		}
		args = args + 1;
	}
	canonical_on();
	return (1);
}
