/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections_handler.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkgosise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 12:37:01 by mkgosise          #+#    #+#             */
/*   Updated: 2017/11/22 11:41:48 by skgatle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h_42sh.h"

static int	redirect_both(char *cmd, t_pipe *info)
{
	if (ft_strstr(cmd, " 2> ") || ft_strstr(cmd, " 2>> "))
	{
		if (redirect_stderr(cmd, info) == -1)
			return (0);
	}
	if (ft_strstr(cmd, " > ") || ft_strstr(cmd, " >> ") ||
			ft_strstr(cmd, " 1> ") || ft_strstr(cmd, " 1>> "))
	{
		if (redirect_stdout(cmd, info) == -1)
			return (0);
	}
	if (ft_strstr(cmd, " < ") || ft_strstr(cmd, " << "))
	{
		if (redirect_stdin(cmd, info) == -1)
			return (0);
	}
	return (1);
}

static int	do_redirection_part_2(char *cmd, t_pipe *info)
{
	if ((ft_strstr(cmd, " < ") || ft_strstr(cmd, " << ")) &&
			(ft_strstr(cmd, " > ") || ft_strstr(cmd, " >> ") ||
			ft_strstr(cmd, " 1> ") || ft_strstr(cmd, " 1>> ") ||
			ft_strstr(cmd, " 2> ") || ft_strstr(cmd, " 2>> ")))
		return (redirect_both(cmd, info));
	if (ft_strstr(cmd, " 2> ") || ft_strstr(cmd, " 2>> "))
	{
		if (redirect_stderr(cmd, info) == -1)
			return (0);
	}
	if (ft_strstr(cmd, " > ") || ft_strstr(cmd, " >> ") ||
			ft_strstr(cmd, " 1> ") || ft_strstr(cmd, " 1>> "))
	{
		if (redirect_stdout(cmd, info) == -1)
			return (0);
	}
	if (ft_strstr(cmd, " < ") || ft_strstr(cmd, " << "))
	{
		if (redirect_stdin(cmd, info) == -1)
			return (0);
	}
	return (1);
}

static int	do_redirection_part_1(char *cmd, t_pipe *info)
{
	if (ft_strstr(cmd, " >&- ") || ft_strstr(cmd, " >& - ") ||
			ft_strstr(cmd, " 1>&- ") || ft_strstr(cmd, " 1>& - ") ||
			ft_strstr(cmd, " 2>&- ") || ft_strstr(cmd, " 2>& - ") ||
			ft_strstr(cmd, " <&- ") || ft_strstr(cmd, " <& - "))
	{
		if (close_std(cmd, info) == -1)
			return (0);
	}
	if (ft_strstr(cmd, " >&2 ") || ft_strstr(cmd, " 1>&2 ") ||
			ft_strstr(cmd, " 2>&1 "))
	{
		if (redirect_std_to_std(cmd, info) == -1)
			return (0);
	}
	if (ft_strstr(cmd, " >& ") || ft_strstr(cmd, " &> ") ||
			ft_strstr(cmd, " >>& ") || ft_strstr(cmd, " &>> "))
	{
		if (redirect_std_errin_fd(cmd, info) == -1)
			return (0);
	}
	return (1);
}

int			redirection_handler(char *cmd, t_pipe *info)
{
	char *new_cmd;

	if (!(new_cmd = append_str(cmd)))
		return (0);
	if (is_redirect(new_cmd) || is_close_std(new_cmd) ||
			is_redirect_stdtostd(new_cmd))
	{
		if (!(validate_redirect(new_cmd)))
		{
			ft_putstr_fd("Ambiguous input redirect\n", 2);
			return (-1);
		}
		info->r_flag = TRUE;
		info->cmd = cmd;
		if (!do_redirection_part_1(new_cmd, info))
			return (-1);
		if (!do_redirection_part_2(new_cmd, info))
			return (-1);
	}
	ft_strdel(&new_cmd);
	return (1);
}
