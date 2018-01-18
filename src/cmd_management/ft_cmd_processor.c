/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd_processor.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmbotho <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 17:45:49 by nmbotho           #+#    #+#             */
/*   Updated: 2017/09/30 17:45:55 by nmbotho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h_42sh.h"

int		contains_local(char *cmd)
{
	int i;

	i = 0;
	while (cmd[i])
	{
		if (cmd[i] == '$')
			return (1);
		i++;
	}
	return (0);
}

void	ft_cat(char *cmd, char *temp, int *k)
{
	int i;

	i = 0;
	while (temp[i])
	{
		cmd[(*k)++] = temp[i];
		i++;
	}
	ft_strdel(&temp);
}

void	ft_fastfaward(char *cmd, char *str, int *k, int *i)
{
	(*i)++;
	while (cmd[*i])
	{
		if (cmd[*i] == '\'')
		{
			(*i)++;
			break ;
		}
		str[(*k)++] = cmd[(*i)++];
	}
}

char	*ft_process_locals(char *cmd)
{
	int		i;
	int		k;
	char	str[4096];
	char	*temp;

	ft_bzero(str, 4096);
	i = 0;
	k = 0;
	if (contains_local(cmd) == 0)
		return (cmd);
	while (cmd[i])
	{
		if (cmd[i] == '\'')
			ft_fastfaward(cmd, str, &k, &i);
		if (cmd[i] == '$')
			ft_cat(str, (temp = ft_key_resolver(cmd, &i)), &k);
		str[k++] = cmd[i];
		if (cmd[i] != '\0')
			i++;
	}
	return (ft_strdup(str));
}

char	**ft_cmd_processor(char *cmd)
{
	char **args;
	char *p_cmd;

	p_cmd = ft_process_locals(cmd);
	args = ft_resolve_args(p_cmd);
	ft_resolve_redirection_args(args);
	return (args);
}
