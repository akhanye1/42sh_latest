/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_basic_input_handler.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmbotho <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 17:11:42 by nmbotho           #+#    #+#             */
/*   Updated: 2018/01/17 10:05:01 by akhanye          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h_42sh.h"

char	*ft_tilder_handler(char *cmd, int *i)
{
	char	*res;
	int		j;
	int		c;
	char	*home;
	int		k;

	if (!(home = ft_getenv("HOME")))
		home = "";
	j = ++(*i);
	c = 0;
	k = -1;
	while (cmd[j] && cmd[j] != '$' && cmd[j] != ' ')
	{
		c++;
		j++;
	}
	res = ft_strnew(ft_strlen(home) + c);
	while (home[++k])
		res[k] = home[k];
	while (c-- > -2)
		res[k++] = cmd[(*i)++];
	res[k] = '\0';
	return (res);
}

char	*ft_prefix_handler(char *cmd, int *i)
{
	int		len;
	int		end;
	int		flag;

	end = *i + 1;
	len = 0;
	flag = 0;
	while (cmd[end] && cmd[end] != '$' && cmd[end] != ' ' && cmd[end] != '\"')
	{
		if (cmd[end] == '}')
			flag = 1;
		if (flag == 0)
			len++;
		end++;
	}
	if (len != -1)
		return (ft_prefix_helper(cmd, i, len, end));
	return (cmd);
}

char	*ft_prefix_helper(char *cmd, int *i, int len, int end)
{
	char *res;
	char *temp;
	char *value;

	res = ft_strsub(cmd, *i + 1, len);
	if (!(value = ft_getenv(res)))
		if (!(value = ft_getlocal(res)))
			value = "";
	ft_strdel(&res);
	temp = ft_strsub(cmd, *i + len + 2, end);
	res = ft_strjoin(value, temp);
	ft_strdel(&temp);
	*i += end;
	return (res);
}

char	*ft_basic_input(char *cmd, int *i)
{
	int		j;
	char	*new;
	int		k;

	j = *i;
	k = 0;
	if (cmd[j] == '\'')
		return (ft_quote_handler(cmd, i));
	else if (cmd[j] == '~')
		return (ft_tilder_handler(cmd, i));
	while (cmd[j] && cmd[j] != '\"' && !ft_isspace(cmd[j]))
		j++;
	new = ft_strnew(j);
	while (cmd[*i] && cmd[*i] != '\"' && !ft_isspace(cmd[*i]))
	{
		new[k] = cmd[*i];
		(*i)++;
		k++;
	}
	ft_continue_if_is_var(i, &k, cmd, new);
	new[k] = '\0';
	return (new);
}

char	*new_cmd(char *cmd)
{
	char *temp;

	if ((temp = ft_strstr(cmd, "&&")))
	{
		*temp = ';';
		*(temp + 1) = ' ';
	}
	if ((temp = ft_strstr(cmd, "||")))
	{
		*temp = ';';
		*(temp + 1) = ' ';
	}
	return (cmd);
}
