/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkgosise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 13:37:19 by mkgosise          #+#    #+#             */
/*   Updated: 2017/09/13 17:01:20 by mkgosise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h_42sh.h"

static int	put_heredoc(char *str)
{
	int	pfd[2];

	if (pipe(pfd) == -1)
	{
		ft_putstr_fd("heredoc error\n", 2);
		return (-1);
	}
	if (dup2(pfd[0], 0) == -1)
	{
		ft_putstr_fd("heredoc error\n", 2);
		return (-1);
	}
	ft_putstr_fd(str, pfd[1]);
	close(pfd[0]);
	close(pfd[1]);
	return (1);
}

int			do_heredoc(char *close_str)
{
	int		res;
	char	*tmp;
	char	*data;
	char	*input;

	data = ft_strnew(0);
	ft_putstr("heredoc> ");
	while (ft_strcmp(close_str, (input = getin())) != 0)
	{
		tmp = ft_strjoin(data, input);
		ft_strdel(&data);
		ft_strdel(&input);
		data = ft_strjoin(tmp, "\n");
		ft_strdel(&tmp);
		ft_putstr("heredoc> ");
	}
	res = put_heredoc(data);
	ft_strdel(&data);
	ft_strdel(&input);
	return (res);
}
