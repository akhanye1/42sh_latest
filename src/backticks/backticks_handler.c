/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backticks_handler.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkgosise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/22 19:38:50 by mkgosise          #+#    #+#             */
/*   Updated: 2017/09/26 11:21:24 by mkgosise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h_42sh.h"

static void	free_2_var(char **var, char **var1)
{
	ft_strdel(var);
	ft_strdel(var1);
}

static char	*run_cmd(char *str, t_pipe *info)
{
	struct s_run_cmd	st;

	st.i = 1;
	while (str[st.i] && str[st.i] != '`' && str[st.i + 1] != '`')
		st.i++;
	st.tmp = ft_strnew(st.i + 2);
	ft_strncpy(st.tmp, str, (st.i + 2));
	if (!(st.trim = ft_strtrim(st.tmp)) || ft_strlen(st.trim) <= 2)
	{
		free_2_var(&st.tmp, &st.trim);
		return (ft_strdup(" "));
	}
	ft_strdel(&st.tmp);
	if (!(st.cmd = ft_strsplit(st.trim, '`')))
	{
		ft_strdel(&st.trim);
		return (ft_strdup(" "));
	}
	ft_strdel(&st.trim);
	st.ret = run_backticks_cmd(*st.cmd, info);
	ft_free2d((void**)st.cmd);
	return (st.ret);
}

static char	*ready_backtick(char *cmd, struct s_ready_backtick st, t_pipe *i)
{
	st.i = 0;
	st.join = ft_strnew(0);
	while ((st.c = cmd[st.i]))
	{
		if (cmd[st.i] == '`')
		{
			st.str = run_cmd(&cmd[st.i], i);
			st.tmp = ft_strjoin(st.join, st.str);
			free_2_var(&st.str, &st.join);
			st.join = st.tmp;
			st.i++;
			while (cmd[st.i] != '`' && cmd[st.i])
				st.i++;
		}
		else
		{
			st.str = ft_strnew(1);
			st.str[0] = st.c;
			st.tmp = ft_strjoin(st.join, st.str);
			free_2_var(&st.str, &st.join);
			st.join = st.tmp;
		}
		st.i++;
	}
	return (st.join);
}

int			backticks_handler(char **cmd, t_pipe *info)
{
	char					*tmp;
	struct s_ready_backtick st;

	st.i = 0;
	if ((tmp = ft_strchr(*cmd, '`')))
	{
		if (ft_strchr(&tmp[1], '`'))
		{
			tmp = ready_backtick(*cmd, st, info);
			ft_strdel(cmd);
			*cmd = tmp;
		}
		else
		{
			ft_putendl_fd("shell: closing backtick not found", 2);
			return (0);
		}
	}
	return (1);
}
