/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edit_subshell.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhanye <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 08:38:22 by akhanye           #+#    #+#             */
/*   Updated: 2018/01/19 08:51:54 by akhanye          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h_42sh.h"

static void			add_to_subshell(t_con *con, char *trimmed)
{
	char	temp[500];
	char	*fr;

	if (!con->shellcommands)
	{
		con->shellcommands = trimmed;
		return ;
	}
	ft_bzero(temp, 500);
	ft_strcpy(temp, " ; ");
	ft_strcat(temp, trimmed);
	fr = con->shellcommands;
	con->shellcommands = ft_strjoin(con->shellcommands, temp);
	free(fr);
	free(trimmed);
}

static int			combine_shell(t_con *con)
{
	if (!con->shellcommands)
		return (FALSE);
	ft_bzero(con->temp, ft_strlen(con->temp));
	ft_strcpy(con->temp, con->shellcommands);
	ft_strdel(&con->shellcommands);
	return (TRUE);
}

int					close_subshell(t_con *con, char *trimmed)
{
	if (trimmed[0] == ')')
	{
		con->subshell--;
		if (con->subshell == 0)
			return (combine_shell(con));
		print_prompt(con);
		ft_strdel(&trimmed);
	}
	ft_strdel(&trimmed);
	return (FALSE);
}

int					combine_subshell(t_con *con, char *trimmed)
{
	add_to_subshell(con, trimmed);
	print_prompt(con);
	return (FALSE);
}

int					add_subshell_commands(t_con *con, char *trimmed)
{
	if (ft_strlen(trimmed) > 1)
		return (report_subshell_error(trimmed, NULL, con));
	con->subshell++;
	ft_strdel(&trimmed);
	print_prompt(con);
	return (FALSE);
}
