/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_stdout.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkgosise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/10 04:08:12 by mkgosise          #+#    #+#             */
/*   Updated: 2017/11/22 12:13:13 by skgatle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h_42sh.h"

int		redirect_stdout(char *cmd, t_pipe *info)
{
	int		fd;
	char	*file;

	fd = 0;
	if (!(file = get_target(cmd, " >> ")) &&
			!(file = get_target(cmd, " > ")) &&
			!(file = get_target(cmd, " 1>> ")) &&
			!(file = get_target(cmd, " 1> ")))
		return (-1);
	if ((ft_strstr(cmd, " >> ") || ft_strstr(cmd, " 1>> ")) && APPEND)
		fd = openfile(file, 1);
	else if (ft_strstr(cmd, " > ") || ft_strstr(cmd, " 1> "))
		fd = openfile(file, 0);
	if (fd == -1 || !(info->file = ft_strdup(file)))
		return (-1);
	ft_strdel(&file);
	if (!isatty(STDOUT_FILENO))
		return (0);
	if (!info->p_flag && dup2(fd, STDOUT_FILENO) == -1)
		return (-1);
	if (info->p_flag == TRUE && (info->fd_red = fd))
		ft_pipe_red(-1, 1, -1, info);
	return (1);
}
