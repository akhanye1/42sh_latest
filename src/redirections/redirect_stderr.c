/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_stderr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkgosise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/10 04:14:30 by mkgosise          #+#    #+#             */
/*   Updated: 2017/10/01 16:45:37 by mkgosise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h_42sh.h"

int		redirect_stderr(char *cmd, t_pipe *info)
{
	int		fd;
	char	*file;

	fd = 0;
	if (!(file = get_target(cmd, " 2>> ")) &&
			!(file = get_target(cmd, " 2> ")))
		return (-1);
	if (ft_strstr(cmd, " 2>> ") && APPEND)
		fd = openfile(file, 1);
	else if (ft_strstr(cmd, " 2> "))
		fd = openfile(file, 0);
	if (fd == -1)
	{
		ft_strdel(&file);
		return (-1);
	}
	ft_strdel(&file);
	if (!isatty(STDERR_FILENO))
		return (0);
	if (!PF && dup2(fd, STDERR_FILENO) == -1)
		return (-1);
	if (info->p_flag == TRUE && (info->fd_red = fd))
		ft_pipe_red(-1, 1, 1, info);
	return (1);
}
