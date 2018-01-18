/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keyaction.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhanye <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 10:49:17 by akhanye           #+#    #+#             */
/*   Updated: 2017/11/21 17:37:12 by akhanye          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h_42sh.h"

static void	input_key(int act, char *temp, t_con *con)
{
	char *copy;

	if (!temp[con->index])
		temp[con->index] = act;
	else
	{
		copy = ft_strdup(temp + con->index);
		temp[con->index] = act;
		ft_strcpy(temp + (con->index + 1), copy);
		free(copy);
	}
	clear_line(temp, con);
	move_cursor('r', &con->index, NULL);
}

static void	input_tab(char *temp, t_con *con)
{
	char	*copy;
	int		n;

	if (!temp[con->index])
		ft_strcat(temp, "    ");
	else
	{
		copy = ft_strdup(temp + con->index);
		ft_strcpy(temp + con->index, "    ");
		ft_strcpy(temp + (con->index + 4), copy);
		free(copy);
	}
	clear_line(temp, con);
	n = -1;
	while (++n < 4)
		move_cursor('r', &(con->index), NULL);
}

void		k_more(int act, char *temp, t_con *con)
{
	int len;

	len = (int)ft_strlen(con->temp);
	if ((act == KEY_CTRL_LEFT && con->index > 1) ||
			(act == KEY_CTRL_RIGHT && con->index < (len - 1)))
		move_word(act, &(con->index), con->temp, con);
	else if (((act == KEY_COPY_RIGHT || act == KEY_END_COPY)
				&& con->index < (len - 1)) ||
			((act == KEY_COPY_LEFT || act == KEY_HOME_COPY) &&
				con->index > 1) || (act == KEY_COPY || act == KEY_PASTE))
		copy_selection(act, &(con->index), con->temp, con);
	else if (act == KEY_CTRL_D)
		ctrld_signal(&(con->index), con->temp, con);
	else if ((act == KEY_TAB) && ((temp[con->index - 1] == ' ') ||
				(con->index == 0) || temp[con->index - 1] == '"'))
		input_tab(con->temp, con);
	else if (act == KEY_TAB)
		search(&(con->temp), &(con->trisearch), con);
}

void		k_action(int act, t_con *con)
{
	int len;

	len = (int)ft_strlen(con->temp);
	if (ft_isprint(act))
		input_key(act, con->temp, con);
	else if (act == KEY_BACKSPACE && con->index > 0)
		del_left(con->temp, &(con->index), con);
	else if (act == KEY_DEL && con->index < len)
		del_right(con->temp, &con->index, con);
	else if (act == KEY_HOME && con->index > 1)
		home_key(&(con->index), con);
	else if (act == KEY_END && con->index < (len - 1))
		end_key(&con->index, ft_strlen(con->temp), con);
	else if (act == KEY_UP)
		find_history('u', &con->index, con->temp, con);
	else if (act == KEY_DOWN)
		find_history('d', &con->index, con->temp, con);
	else if (act == KEY_RIGHT && con->index < len)
		move_cursor('r', &(con->index), con);
	else if (act == KEY_LEFT && con->index > 0)
		move_cursor('l', &(con->index), con);
	else
		k_more(act, con->temp, con);
}
