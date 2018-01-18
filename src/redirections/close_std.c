/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_std.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkgosise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 16:45:19 by mkgosise          #+#    #+#             */
/*   Updated: 2017/10/01 18:21:04 by mkgosise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h_42sh.h"

static void	clean_cmd(char *cmd)
{
	char *ret;

	if ((ret = ft_strstr(cmd, " >&- ")) ||
			(ret = ft_strstr(cmd, " <&- ")))
		ft_memset((void*)&ret[1], ' ', 3);
	if ((ret = ft_strstr(cmd, " >& - ")) ||
			(ret = ft_strstr(cmd, " 1>&- ")) ||
			(ret = ft_strstr(cmd, " 2>&- ")) ||
			(ret = ft_strstr(cmd, " <& - ")))
		ft_memset((void*)&ret[1], ' ', 4);
	if ((ret = ft_strstr(cmd, " 1>& - ")) ||
			(ret = ft_strstr(cmd, " 2>& - ")))
		ft_memset((void*)&ret[1], ' ', 5);
}

int			close_std(char *cmd, t_pipe *info)
{
	if (ft_strstr(cmd, " >&- ") || ft_strstr(cmd, " >& - ") ||
			ft_strstr(cmd, " 1>&- ") || ft_strstr(cmd, " 1>& - "))
		if (!PF || ft_pipe_red(-1, 5, -1, info))
			close(STDOUT_FILENO);
	if (ft_strstr(cmd, " 2>&- ") || ft_strstr(cmd, " 2>& - "))
		if (!PF || ft_pipe_red(-1, 8, 5, info))
			close(STDERR_FILENO);
	if (ft_strstr(cmd, " <&- ") || ft_strstr(cmd, " <& - "))
		close(STDIN_FILENO);
	clean_cmd(cmd);
	return (1);
}
