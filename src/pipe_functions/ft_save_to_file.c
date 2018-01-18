/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_save_to_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skgatle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 06:35:33 by skgatle           #+#    #+#             */
/*   Updated: 2017/12/19 08:04:25 by skgatle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h_42sh.h"

int				ft_cmd_rerun(t_pipe *i)
{
	pid_t	pid;
	char	*bf[3];

	bf[0] = "cat";
	bf[1] = i->file;
	bf[2] = NULL;
	if (!(pid = fork()))
	{
		dup2(i->fd_red, STDIN_FILENO);
		if (i->p_last)
			dup2(i->fildes[1], STDOUT_FILENO);
		execve(i->path, i->arg, ft_get_environ());
		ft_cmderror("Failed to run command : ", "Error");
	}
	return (1);
}

int				ft_save_to_file(t_pipe *i)
{
	pid_t	pid2;
	char	*bf[4];

	if (i->fd[0] == 1 && ft_cmd_rerun(i) == 1)
		return (1);
	ft_append(bf, i);
	i->fd[2] = -1;
	if (!(pid2 = fork()))
	{
		ft_close_fds(i, 't');
		execve("/usr/bin/tee", bf, ft_get_environ());
		ft_cmderror("Failed to run command : ", "Error");
	}
	else
	{
		close(i->fildes2[1]);
		wait(&pid2);
		if (i->fd[1] != 5 && i->fd[1] != 8)
			ft_strdel(&i->file);
	}
	return (1);
}
