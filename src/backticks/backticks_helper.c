/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backticks_helper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkgosise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/22 20:12:39 by mkgosise          #+#    #+#             */
/*   Updated: 2018/01/09 09:28:33 by nmbotho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h_42sh.h"

static char	*get_output(char *file)
{
	int		fd;
	char	*ret;
	char	*tmp;
	char	*tmp2;

	if ((fd = open(file, O_RDONLY)) == -1)
		return (NULL);
	ret = ft_strnew(0);
	while (get_next_line(fd, &tmp))
	{
		tmp2 = ft_strjoin(ret, tmp);
		ft_strdel(&ret);
		ret = ft_strjoin(tmp2, " ");
		ft_strdel(&tmp2);
	}
	ft_strdel(&tmp);
	if (close(fd) == -1 || unlink(file) == -1)
	{
		ft_strdel(&ret);
		return (NULL);
	}
	return (ret);
}

char		*run_backticks_cmd(char *cmd, t_pipe *info)
{
	int		fd;
	int		stdout;
	char	**tmp_args;

	if (!cmd)
		return (NULL);
	if ((stdout = dup(STDOUT_FILENO)) == -1)
		return (NULL);
	if ((fd = openfile("/tmp/42sh", 0)) == -1)
	{
		dup2(stdout, STDOUT_FILENO);
		return (NULL);
	}
	if (dup2(fd, STDOUT_FILENO) == -1)
	{
		dup2(stdout, STDOUT_FILENO);
		return (NULL);
	}
	if (!ft_strstr(*(tmp_args = filter_out_redirections(cmd)), "exit"))
		ft_execute_handler(cmd, info);
	ft_free2d((void**)tmp_args);
	if (dup2(stdout, STDOUT_FILENO) == -1)
		return (NULL);
	return (get_output("/tmp/42sh"));
}
