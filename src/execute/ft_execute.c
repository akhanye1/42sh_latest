/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skgatle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/04 11:36:00 by skgatle           #+#    #+#             */
/*   Updated: 2018/01/10 10:01:56 by skgatle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h_42sh.h"
#define PIPE_RED info->pip_red

int				ft_check_pips(t_pipe *info)
{
	if (info->p_last == TRUE && info->p_flag && !info->r_flag)
		ft_initialize_pipes(info->fd_in, info->fildes[1]);
	else if (info->p_last == FALSE && info->p_flag && !info->r_flag)
		ft_initialize_pipes(info->fd_in, 1);
	if (!info->p_flag)
		signal(SIGINT, ft_handle_all);
	else
		signal(SIGINT, ft_handle_psignal);
	return (1);
}

char			*get_binpath(char *bin_name)
{
	struct s_get_binpath	st;

	st.i = -1;
	if (ft_strchr(bin_name, '/'))
		if (access(bin_name, F_OK) != -1 && access(bin_name, X_OK) != -1)
			return (ft_strdup(bin_name));
	if (!(st.path_str = ft_getenv("PATH")))
		return (NULL);
	st.paths = ft_strsplit(st.path_str, ':');
	while (st.paths[++st.i])
	{
		st.tmp = ft_strjoin(st.paths[st.i], "/");
		st.ret = ft_strjoin(st.tmp, bin_name);
		ft_strdel(&st.tmp);
		if (access(st.ret, F_OK) != -1 && access(st.ret, X_OK) != -1)
		{
			ft_free2d((void**)st.paths);
			return (st.ret);
		}
		ft_strdel(&st.ret);
	}
	ft_free2d((void**)st.paths);
	return (NULL);
}

static int		ft_exe_cmd(t_pipe *info, char **args)
{
	char	*bin;

	ft_check_pips(info);
	if (!(bin = get_binpath(*args)))
	{
		ft_putstr_fd("42sh: command not found: ", 2);
		ft_putendl_fd(*args, 2);
		exit(0);
	}
	if ((execve(bin, args, ft_get_environ()) == -1))
		exit(0);
	return (1);
}

int				ft_execute(char **args, char *cmd, t_pipe *info)
{
	pid_t	pid;
	int		status;

	status = 1;
	if ((info->r_flag && info->p_flag) || builtin(args, cmd, info) || PIPE_RED)
		return (1);
	if (!(pid = fork()))
		ft_exe_cmd(info, args);
	else if (pid < 0)
		return (-1);
	else if (!info->p_flag)
		while ((status == 1) || (!WIFEXITED(status) && !WIFSIGNALED(status)))
			waitpid(pid, &status, WUNTRACED);
	else if (info->p_flag == TRUE && !info->r_flag)
	{
		info->pid_prev = info->pid_cur;
		info->pid_cur = pid;
	}
	return (1);
}

void			ft_execute_handler(char *cmd, t_pipe *info)
{
	int		stdin;
	int		stdout;
	int		stderr;
	int		status;
	char	**args;

	if (ft_store_fd(&stdin, &stdout, &stderr) == -1)
		return ;
	status = redirection_handler(cmd, info);
	if (status != -1)
	{
		args = filter_out_redirections(cmd);
		if (args && countlist(args))
			ft_execute(args, cmd, info);
		ft_free2d((void**)args);
	}
	info->pip_red = FALSE;
	if (ft_restore_fd(stdin, stdout, stderr) == -1)
		return ;
}
