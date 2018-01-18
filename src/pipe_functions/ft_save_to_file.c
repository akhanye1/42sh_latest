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

	if (!(pid = fork()))
	{
        dup2(i->fildes2[1], 1);
        dup2(i->redin, 0);
        execve(i->path, i->arg, ft_get_environ());
    }
    else
    {
    	wait(&pid);
    }
	return (1);
}

int				ft_save_to_file(t_pipe *i)
{
	pid_t	pid2;
	char	*bf[4];

	if (i->fd[0] == 1 && !ft_cmd_rerun(i))
		return (1);
	ft_append(bf, i);
	i->fd[2] = -1;
	if (!(pid2 = fork()))
	{
		if (i->fd[0] != 1)
			ft_close_fds(i, 't');
		else
			dup2(i->fildes2[0], 0);
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
