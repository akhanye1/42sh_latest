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

static int	report_subshell_error(char *trimmed, char *stripped, t_con *con, char **line)
{
	ft_putendl("\n42sh: parse error near '('");
	if (trimmed)
		free(trimmed);
	if (stripped)
		free(stripped);
	print_prompt(con);
	con->subshell = 0;
	if (con->shellcommands)
		ft_strdel(&con->shellcommands);
	return (get_key_line(line, con));
}


static int	formatted_subshell(char *trimmed, char **line, t_con *con)
{
	int		last_index;

	if (bracketsokay(trimmed))
	{
		last_index = ft_strchr(trimmed, ')') - trimmed;
		*line = ft_strsub(trimmed, 1, last_index - 1);
		return (TRUE);
	}
	return (report_subshell_error(trimmed, NULL, con, line));
}

static void	add_to_subshell(t_con *con, char *trimmed)
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

static int	add_subshell_commands(char **line, t_con *con, char *trimmed)
{
	int		index;
	char	*str;
	char	*stripped;

	if (trimmed[0] == '(')
	{
		if (!(stripped = ft_strtrim(trimmed + 1)))
			return (report_subshell_error(trimmed, NULL, con, line));
		if (stripped[0] == '(')
			return (report_subshell_error(trimmed, stripped, con, line));
		con->subshell++;
		if (ft_strchr(stripped, '('))
		{
			index = ft_strchr(stripped, '(') - trimmed;
			str = ft_strsub(stripped, index + 1, ft_strlen(stripped));
			free(trimmed);
			trimmed = ft_strsub(stripped, 0, index - 1);
			add_to_subshell(con, trimmed);
			return (manage_subshell(line, con, trimmed));
		}
		add_to_subshell(con, stripped);
		free(trimmed);
		print_prompt(con);
		return (get_key_line(line, con));
	}
	if (con->subshell == 0)
		return (report_subshell_error(trimmed, NULL, con, line));
	con->subshell++;
	index = ft_strchr(trimmed, '(') - trimmed;
	stripped = ft_strsub(trimmed, 0, index - 1);
	add_to_subshell(con, stripped);
	return (manage_subshell(line, con, trimmed + (index + 1)));
}

int		combine_shell(t_con *con, char **line)
{
	if (!con->shellcommands)
		return (get_key_line(line, con));
	*line = ft_strdup(con->shellcommands);
	ft_putstr("Command Given : ");
	ft_putendl(*line);
	ft_strdel(&con->shellcommands);
	return (TRUE);
}

int		close_subshell(t_con *con, char **line, char *trimmed)
{
	int		index;
	char	*str;

	if (trimmed[0] == ')')
	{
		con->subshell--;
		if (con->subshell == 0)
		{
			free(trimmed);
			return (combine_shell(con, line));
		}
		print_prompt(con);
		return (get_key_line(line, con));
	}
	index = ft_strchr(trimmed, ')') - trimmed;
	str = ft_strsub(trimmed, 0, index - 1);
	add_to_subshell(con, str);
	return (combine_shell(con, line));
}

int		combine_subshell(char **line, t_con *con, char *trimmed)
{
	add_to_subshell(con, trimmed);
	print_prompt(con);
	return (get_key_line(line, con));
}

int		manage_subshell(char **line, t_con *con, char *trimmed)
{
	if (trimmed[0] == '(' && ft_strstr(trimmed, ")") &&
			con->subshell == 0)
		return (formatted_subshell(trimmed, line, con));
	if (ft_strstr(trimmed, "("))
		add_subshell_commands(line, con, trimmed);
	else if (ft_strstr(trimmed, ")"))
		close_subshell(con, line, trimmed);
	else
		combine_subshell(line, con, trimmed);
	return (TRUE);
}
