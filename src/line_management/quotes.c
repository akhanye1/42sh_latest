/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhanye <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/22 15:29:07 by akhanye           #+#    #+#             */
/*   Updated: 2018/01/19 12:01:17 by akhanye          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h_42sh.h"

char		quote_okay(char *str, t_con *con)
{
	int	double_q;
	int single_q;
	int	back_q;
	int i;

	double_q = 1;
	single_q = 1;
	back_q = 1;
	i = -1;
	while (str[++i])
	{
		if (str[i] == '"')
			double_q = !(double_q % 2);
		if (str[i] == '\'')
			single_q = !(single_q % 2);
		if (str[i] == '`')
			back_q = !(back_q % 2);
	}
	con->closequote = (double_q && single_q && back_q);
	return (con->closequote);
}

char		check_multiline(t_con *con, char **line)
{
	char	*fr;

	if (con->multiline)
	{
		fr = ft_strdup(con->temp);
		ft_strcpy(con->temp, con->multiline);
		ft_strcat(con->temp, fr);
		ft_strdel(&(con->multiline));
		free(fr);
		(*line) = ft_strdup(con->temp);
	}
	if (!(quote_okay(con->temp, con)))
	{
		con->multiline = ft_strjoin(con->temp, "\n");
		ft_bzero(con->temp, ft_strlen(con->temp));
		fr = con->temp;
		print_prompt(con);
		return (FALSE);
	}
	return (TRUE);
}

static void	combine_lines(char *trimmed, t_con *con)
{
	char *fr;

	ft_strncpy(con->temp, trimmed, ft_strlen(trimmed) - 2);
	con->temp[ft_strlen(trimmed) - 2] = '\0';
	if (con->morecommands)
	{
		fr = con->morecommands;
		con->morecommands = ft_strjoin(con->morecommands, " ");
		free(fr);
		fr = con->morecommands;
		con->morecommands = ft_strjoin(con->morecommands, con->temp);
		free(fr);
		fr = con->morecommands;
		con->morecommands = ft_strjoin(con->morecommands, " ");
		free(fr);
	}
	else
		con->morecommands = ft_strjoin(con->temp, " ");
	ft_bzero(con->temp, ft_strlen(con->temp));
	con->morelines = 0;
	print_prompt(con);
	free(trimmed);
}

char		command_okay(t_con *con, char **line)
{
	char	*trimmed;
	char	*fr;

	if (!(trimmed = ft_strtrim(con->temp)))
		return (TRUE);
	if (con->morecommands)
	{
		fr = ft_strdup(trimmed);
		ft_strcpy(con->temp, con->morecommands);
		ft_strcat(con->temp, fr);
		free(fr);
		(*line) = ft_strdup(con->temp);
	}
	if (ft_strlen(trimmed) > 1 &&
			trimmed[ft_strlen(trimmed) - 1] == '\\')
	{
		combine_lines(trimmed, con);
		return (FALSE);
	}
	if (con->morecommands)
		ft_strdel(&(con->morecommands));
	con->morelines = 1;
	free(trimmed);
	return (TRUE);
}

char		check_line(t_con *con, char **line)
{
	char *trimmed;

	ft_putchar('\n');
	remove_below();
	if (!check_multiline(con, line))
		return (get_key_line(line, con));
	if (!command_okay(con, line))
		return (get_key_line(line, con));
	if (!(trimmed = ft_strtrim(con->temp)))
		return (temp_failure(line, con));
	if (!(manage_subshell(con, trimmed)))
		return (get_key_line(line, con));
	if (ft_strlen(trimmed) > 0 && trimmed[0] != '!'
			&& !ft_strequ(trimmed, "history"))
		add_history(line, con);
	else
	{
		if (ft_strequ(trimmed, "history"))
			return (history_command(line, con));
		else if (!action_history(trimmed, con, line))
			return (get_key_line(line, con));
	}
	free(trimmed);
	return (TRUE);
}
