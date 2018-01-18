/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_std_to_std.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkgosise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 15:50:27 by mkgosise          #+#    #+#             */
/*   Updated: 2017/09/26 14:14:15 by mkgosise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h_42sh.h"

int		redirect_std_to_std(char *cmd, t_pipe *info)
{
	if (ft_strstr(cmd, " >&2 ") || ft_strstr(cmd, " 1>&2 "))
	{
		if (!PF)
			if (dup2(STDERR_FILENO, STDOUT_FILENO) == -1)
				return (-1);
		if (PF && (info->file = ft_strdup("/dev/stderr")))
			ft_pipe_red(-1, 2, 3, info);
	}
	else if (ft_strstr(cmd, " 2>&1 "))
	{
		if (!PF)
			if (dup2(STDOUT_FILENO, STDERR_FILENO) == -1)
				return (-1);
		if (PF && (info->file = ft_strdup("/tmp/data")))
			ft_pipe_red(-1, 3, 2, info);
	}
	return (1);
}
