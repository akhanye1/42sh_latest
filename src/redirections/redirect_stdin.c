/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_stdin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkgosise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/10 04:19:13 by mkgosise          #+#    #+#             */
/*   Updated: 2018/01/18 17:48:52 by skgatle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h_42sh.h"

static int	get_file_fd(char *file)
{
	if (access(file, F_OK) == -1)
	{
		ft_putstr_fd("no such file or directory: ", 2);
		ft_putendl_fd(file, 2);
		return (-1);
	}
	return (open(file, (O_RDONLY)));
}

int			redirect_stdin(char *cmd, t_pipe *info)
{
	int		fd;
	char	*file;

	fd = 0;
	if (!(file = get_target(cmd, " << ")) &&
			!(file = get_target(cmd, " < ")))
		return (-1);
	if (ft_strstr(cmd, " << "))
	{
		fd = do_heredoc(file);
		ft_strdel(&file);
		return (fd);
	}
	else if (ft_strstr(cmd, "<"))
		fd = get_file_fd(file);
	if (fd == -1 || !(info->redin = fd))
		return (-1);
	ft_strdel(&file);
	if (!isatty(STDIN_FILENO))
		return (0);
	if (!PF && dup2(fd, STDIN_FILENO) == -1)
		return (-1);
	if (info->p_flag == TRUE)
		ft_pipe_red(1, -1, -1, info);
	return (1);
}
