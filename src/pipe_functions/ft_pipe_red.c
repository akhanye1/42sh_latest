/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe_red.c.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skgatle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/24 17:50:15 by skgatle           #+#    #+#             */
/*   Updated: 2018/01/09 07:57:01 by skgatle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h_42sh.h"

void					ft_close_fds(t_pipe *inf, char type)
{
	if (type == 't')
		ft_setfd_for_tee(inf);
	else if (type == 'm')
		ft_setfd_for_main(inf);
}

static void				ft_execute_pcmd(t_pipe *info)
{
	char *builtins;

	builtins = ft_strdup("echo cd setenv unsetenv exit");
	ft_initialize_pipes(info->fd_in, 1);
	ft_close_fds(info, 'm');
	if (ft_strstr(builtins, info->arg[0]))
	{
		builtin(info->arg, info->cmd, info);
		exit(EXIT_SUCCESS);
	}
	execve(info->path, info->arg, ft_get_environ());
	ft_cmderror("Failed to run command : ", "Error");
}

int						ft_pipe_red(int in, int out, int err, t_pipe *inf)
{
	pid_t	pid;

	inf->fd[0] = in;
	inf->fd[1] = out;
	inf->fd[2] = err;
	inf->arg = filter_out_redirections(inf->cmd);
	inf->path = get_binpath(*(inf->arg));
	pipe(inf->fildes2);
	signal(SIGINT, ft_handle_psignal);
	if (inf->append == FALSE)
		inf->append = (out == 1 && err == 1) ? TRUE : FALSE;
	if (!(pid = fork()))
		ft_execute_pcmd(inf);
	else if ((inf->r_flag = TRUE))
	{
		inf->pip_red = TRUE;
		inf->pid_prev = inf->pid_cur;
		inf->pid_cur = pid;
		ft_check_for_error(close(inf->fildes2[1]));
	}
	return (1);
}
