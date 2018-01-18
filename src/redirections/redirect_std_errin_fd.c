/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_std_inerr_fd.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkgosise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/13 13:31:18 by mkgosise          #+#    #+#             */
/*   Updated: 2017/09/14 16:51:47 by mkgosise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h_42sh.h"

static int	is_append_output(char *cmd)
{
	if (ft_strstr(cmd, " &>> ") || ft_strstr(cmd, " >>& "))
		return (1);
	return (0);
}

int			redirect_std_errin_fd(char *cmd, t_pipe *info)
{
	int		fd;
	char	*file;

	fd = 0;
	if (!(file = get_target(cmd, " &> ")) &&
			!(file = get_target(cmd, " >& ")) &&
			!(file = get_target(cmd, " &>> ")) &&
			!(file = get_target(cmd, " >>& ")))
		return (-1);
	if (is_append_output(cmd) && APPEND)
		fd = openfile(file, 1);
	else
		fd = openfile(file, 0);
	if (fd == -1 && !(info->file = ft_strdup(file)))
	{
		ft_strdel(&file);
		return (1);
	}
	ft_strdel(&file);
	if (info->p_flag == FALSE)
		if ((dup2(fd, STDOUT_FILENO) == -1 || dup2(fd, STDERR_FILENO) == -1))
			return (-1);
	if (info->p_flag == TRUE && (info->fd_red = fd))
		ft_pipe_red(-1, 1, 1, info);
	return (1);
}
