/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_action.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhanye <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 10:02:39 by akhanye           #+#    #+#             */
/*   Updated: 2017/11/07 10:07:11 by akhanye          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h_42sh.h"

static char	get_history_index(char *str, t_con *con, char **line)
{
	int			num;
	t_history	*temp;

	num = ft_atoi(str);
	temp = con->history;
	if (num < 0 && temp)
		num = (temp->num + num) + 1;
	while (temp)
	{
		if (temp->num == num)
		{
			(*line) = temp->name;
			return (TRUE);
		}
		temp = temp->prev;
	}
	print_prompt(con);
	return (FALSE);
}

static char	get_history_key(char *trimmed, t_con *con, char **line)
{
	t_history	*temp;
	int			len;

	temp = con->history;
	len = ft_strlen(trimmed);
	while (temp)
	{
		if (ft_strnequ(trimmed, temp->name, len))
		{
			(*line) = temp->name;
			return (TRUE);
		}
		temp = temp->prev;
	}
	print_prompt(con);
	return (FALSE);
}

static char	get_prev_command(t_con *con, char **line)
{
	if (!con->history)
		return (FALSE);
	(*line) = con->history->name;
	return (TRUE);
}

static char	get_str_str(char *str, t_con *con, char **line)
{
	t_history *temp;

	temp = con->history;
	if (!temp)
		return (FALSE);
	while (temp)
	{
		if (ft_strstr(temp->name, str))
		{
			(*line) = temp->name;
			return (TRUE);
		}
		temp = temp->prev;
	}
	return (FALSE);
}

char		action_history(char *trimmed, t_con *con, char **line)
{
	if (ft_isdigit(trimmed[1]) || trimmed[1] == '-')
		return (get_history_index(trimmed + 1, con, line));
	else if (ft_strequ(trimmed, "!!"))
		return (get_prev_command(con, line));
	else if (trimmed[1] == '?')
		return (get_str_str(trimmed + 2, con, line));
	else
		return (get_history_key(trimmed + 1, con, line));
}
