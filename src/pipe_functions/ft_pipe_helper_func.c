/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe_helper_func.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skgatle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 06:32:25 by skgatle           #+#    #+#             */
/*   Updated: 2017/12/19 07:44:24 by skgatle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h_42sh.h"

static void				ft_re_stdout_err(t_pipe *inf)
{
	ft_check_for_error(dup2(inf->fildes2[1], STDERR_FILENO));
	ft_check_for_error(dup2(STDERR_FILENO, STDOUT_FILENO));
}

void					ft_setfd_for_tee(t_pipe *inf)
{
	int fd;

	if (!inf->p_last && (fd = open("/dev/null", O_RDWR)) &&
			inf->fd[2] != 1 && inf->fd[1] != 3 && OUT_ND_IN)
		ft_check_for_error(dup2(fd, STDOUT_FILENO));
	else if (inf->fd[1] == 2 && inf->fd[2] == -1)
	{
		fd = open("/dev/stderr", O_RDWR | O_APPEND | O_CREAT, 0666);
		ft_check_for_error(dup2(STDERR_FILENO, fd));
		ft_check_for_error(dup2(inf->fildes[1], STDOUT_FILENO));
	}
	else if ((inf->fd[1] == 3 && inf->p_flag) || inf->fd[1] == 1 ||
			(inf->fd[1] == 8 && inf->p_flag))
		ft_check_for_error(dup2(inf->fildes[1], STDOUT_FILENO));
	else if (inf->fd[0] == 1)
	{
		inf->fd_red = open("/tmp/data", O_RDWR | O_CREAT, 0666);
		ft_check_for_error(dup2(fd, STDOUT_FILENO));
		ft_check_for_error(dup2(inf->fildes[0], STDIN_FILENO));
	}
	ft_check_for_error(dup2(inf->fildes2[0], STDIN_FILENO));
}

void					ft_setfd_for_main(t_pipe *inf)
{
	int fd;

	if (inf->fd[1] == 1 && inf->fd[2] == 1 && (inf->fd[2] = -1))
		ft_check_for_error(dup2(inf->fd_red, 2));
	ft_check_for_error(close(inf->fildes2[0]));
	if (inf->fd[2] == 1 && (inf->fd[2] = -1))
		ft_check_for_error(dup2(inf->fd_red, 2));
	if (inf->fd[1] == 2 && inf->fd[2] == 3)
		ft_re_stdout_err(inf);
	else if (inf->fd[1] == 3 && inf->fd[2] == 2)
	{
		ft_check_for_error(dup2(inf->fildes2[1], STDOUT_FILENO));
		ft_check_for_error(dup2(STDOUT_FILENO, STDERR_FILENO));
	}
	else if (inf->fd[1] == 5 && (fd = open("/dev/null", O_RDWR)))
		ft_check_for_error(dup2(fd, STDOUT_FILENO));
	else if (inf->fd[2] == 5 && (fd = open("/dev/null", O_RDWR)))
	{
		ft_check_for_error(dup2(fd, STDERR_FILENO));
		ft_check_for_error(dup2(inf->fildes2[1], STDOUT_FILENO));
	}
	else
		ft_check_for_error(dup2(inf->fildes2[1], STDOUT_FILENO));
}
