/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subshell.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhanye <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 11:26:01 by akhanye           #+#    #+#             */
/*   Updated: 2018/01/18 13:56:40 by akhanye          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h_42sh.h"

static char	bracketsokay(char *trimmed)
{
	char	brackets[50];
	int		i;
	int		foundindex;
	int		bracketsfound;

	ft_bzero(brackets, 50);
	i = -1;
	foundindex = -1;
	bracketsfound = 0;
	while (trimmed[++i])
	{
		if (trimmed[i] == '(')
		{
			brackets[++foundindex] = '(';
			if (++bracketsfound == 2)
				return (FALSE);
		}
		if (trimmed[i] == ')')
		{
			if (foundindex == -1)
				return (FALSE);
			if (brackets[foundindex--] != '(')
				return (FALSE);
		}
	}
	return (foundindex == -1);
}

int	report_subshell_error(char *trimmed, char *stripped, t_con *con)
{
	ft_putendl("\n42sh: parse error near '('");
	if (trimmed)
		free(trimmed);
	if (stripped)
		free(stripped);
	con->subshell = 0;
	print_prompt(con);
	if (con->shellcommands)
		ft_strdel(&con->shellcommands);
	return (FALSE);
}


static int	formatted_subshell(char *trimmed, t_con *con)
{
	int		last_index;
	char	*fr;

	if (bracketsokay(trimmed))
	{
		last_index = ft_strchr(trimmed, ')') - trimmed;
		fr = ft_strsub(trimmed, 1, last_index - 1);
		ft_bzero(con->temp, ft_strlen(con->temp));
		ft_strcpy(con->temp, fr);
		ft_strdel(&fr);
		return (TRUE);
	}
	return (report_subshell_error(trimmed, NULL, con));
}

int		manage_subshell(t_con *con, char *trimmed)
{
	if (ft_strlen(trimmed) == 0)
		return (FALSE);
	if (con->subshell || trimmed[0] == '(')
	{
		if (trimmed[0] == '(' && ft_strstr(trimmed, ")") &&
				con->subshell == 0)
			return (formatted_subshell(trimmed, con));
		else if (trimmed[0] == '(')
			return (add_subshell_commands(con, trimmed));
		else if (trimmed[0] == ')')
			return (close_subshell(con, trimmed));
		else if (ft_strstr(trimmed, "(") ||
				ft_strstr(trimmed, ")"))
			return (report_subshell_error(trimmed, NULL, con));
		else
			return (combine_subshell(con, trimmed));
	}
	return (TRUE);
}
