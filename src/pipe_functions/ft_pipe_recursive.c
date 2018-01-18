/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe_recursive.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skgatle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 15:15:26 by skgatle           #+#    #+#             */
/*   Updated: 2018/01/09 10:28:52 by akhanye          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h_42sh.h"

void				ft_timer(void)
{
	int n;

	n = 0;
	while (n < 12000000)
		n++;
}

static void			ft_close_recursion(t_pipe *info)
{
	if (info->r_flag && !(info->r_flag = 0))
	{
		ft_save_to_file(info);
		close(info->fildes2[1]);
	}
}

int					ft_pipe_recursive(char **p_args, int in, t_pipe *info)
{
	if (!*(p_args + 1))
	{
		info->p_last = FALSE;
		info->fd_in = in;
		ft_execute_handler(*p_args, info);
		wait(&info->pid_cur);
		ft_close_recursion(info);
		ft_timer();
		if (!info->builtin_act)
			kill(info->pid_prev, SIGINT);
	}
	else if (pipe(info->fildes) == 0)
	{
		info->p_last = TRUE;
		info->fd_in = in;
		ft_execute_handler(*p_args, info);
		ft_close_recursion(info);
		close(info->fildes[1]);
		ft_pipe_recursive(p_args + 1, info->fildes[0], info);
		wait(&info->pid_cur);
		if (!info->builtin_act || (info->builtin_act = FALSE))
			kill(0, SIGINT);
	}
	return (1);
}
