/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmbotho <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 17:10:04 by nmbotho           #+#    #+#             */
/*   Updated: 2017/09/30 17:10:11 by nmbotho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h_42sh.h"

char	*ft_quote_handler(char *cmd, int *i)
{
	int		k;
	int		j;
	char	*new;

	j = *i + 1;
	k = 0;
	while (cmd[j] && cmd[j] != '\'')
	{
		j++;
		(*i)++;
		k++;
	}
	(*i)++;
	new = ft_strnew(j);
	new[k--] = '\0';
	j--;
	while (k > -1)
	{
		new[k] = cmd[j];
		k--;
		j--;
	}
	if (!cmd[*i])
		(*i)--;
	return (new);
}

char	*ft_dquote_handler(char *cmd, int *i)
{
	int		j;
	int		k;
	char	*new;

	(*i)++;
	j = *i;
	k = 0;
	while (cmd[j] && cmd[j] != '\"')
		j++;
	new = ft_strnew(j);
	while (cmd[*i] && cmd[*i] != '\"')
	{
		new[k] = cmd[*i];
		k++;
		(*i)++;
	}
	new[k] = '\0';
	if (cmd[*i] == '\0')
		(*i)--;
	return (new);
}

char	*ft_key_resolver(char *cmd, int *i)
{
	int		k;
	char	value[4096];
	char	*key;

	(*i)++;
	k = 0;
	key = NULL;
	if (cmd[*i] == '{')
		return (ft_prefix_handler(cmd, i));
	while (cmd[*i] && cmd[*i] != '\"' && cmd[*i] != '$' && !ft_isspace(cmd[*i]))
	{
		value[k] = cmd[*i];
		(*i)++;
		k++;
	}
	value[k] = '\0';
	if (!(key = ft_getlocal(value)))
		if (!(key = ft_getenv(value)))
			key = "";
	return (ft_strdup(key));
}

int		ft_count_args(char *cmd)
{
	int i;
	int c;

	i = 0;
	c = 0;
	while (cmd[i])
	{
		if (!ft_isspace(cmd[i]) && cmd[i] != '\"')
		{
			c++;
			while (cmd[i] && !ft_isspace(cmd[i]) && cmd[i] != '\"')
				i++;
		}
		else if (cmd[i] == '\"')
		{
			c++;
			if (cmd[i] == '\"')
				i++;
			while (cmd[i] && cmd[i] != '\"' && cmd[i] != '$')
				i++;
		}
		if (cmd[i] != '\0')
			i++;
	}
	return (c);
}

char	**ft_resolve_args(char *cmd)
{
	int		count;
	char	**new;
	int		index;
	int		i;

	i = 0;
	index = 0;
	count = ft_count_args(cmd);
	new = (char **)malloc(sizeof(char *) * count + 1);
	while (cmd[i])
	{
		if (!ft_isspace(cmd[i]))
		{
			if (cmd[i] == '\"')
				new[index++] = ft_dquote_handler(cmd, &i);
			else
				new[index++] = ft_basic_input(cmd, &i);
		}
		if (cmd[i])
			i++;
	}
	new[index] = NULL;
	ft_resolve_redirection_args(new);
	return (new);
}
