/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skgatle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/01 18:00:33 by skgatle           #+#    #+#             */
/*   Updated: 2017/12/18 16:21:26 by skgatle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h_42sh.h"

int			builtin(char **args, char *cmd, t_pipe *info)
{
	ft_check_pips(info);
	if (!ft_validate(args))
		return (0);
	if (ft_strcmp(*args, "env") == 0 && (info->builtin_act = TRUE))
		ft_env(args);
	else if (ft_strcmp(*args, "exit") == 0)
		ft_exit(args, cmd);
	else if (ft_strcmp(*args, "setenv") == 0)
		ft_setenv_main(args);
	else if (ft_strcmp(*args, "unsetenv") == 0)
		ft_unset_main(args);
	else if (ft_strcmp(*args, "echo") == 0 && (info->builtin_act = TRUE))
		echo_handler(args);
	else if (ft_strcmp(*args, "cd") == 0 && (info->builtin_act = TRUE))
		ft_cd(args);
	else if (ft_set_local_main(args))
		return (1);
	else if (ft_strcmp(*args, "export") == 0)
		ft_export(args);
	else if (ft_strcmp(*args, "unset") == 0)
		return (ft_unset_local_main(args));
	else
		return (0);
	return (1);
}
