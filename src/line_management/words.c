/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_words.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhanye <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 11:21:31 by akhanye           #+#    #+#             */
/*   Updated: 2017/09/08 14:52:20 by akhanye          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h_42sh.h"

static void	position_cursor(int pos, t_con *con)
{
	char	buf[20];
	char	*ap;

	ft_bzero(buf, 20);
	ap = buf;
	tputs(tgoto(tgetstr("cm", &ap), pos + 3, con->screen.min_y), 1, ft_puts);
}

static void	move_left(int *i, char *temp, t_con *con)
{
	int x;

	x = *i;
	while (temp[x] != ' ' && temp[x] != '\t' && x > 0)
		x--;
	while ((temp[x] == ' ' || temp[x] == '\t') && x > 0)
		x--;
	while (temp[x] != ' ' && temp[x] != '\t' && x > 0)
		x--;
	if (x == 0)
		home_key(i, con);
	else
	{
		(*i) = x + 1;
		position_cursor((*i), con);
	}
}

static void	move_right(int *i, char *temp, t_con *con)
{
	int x;

	x = (*i);
	while (temp[x] != ' ' && temp[x] != '\t' && temp[x])
		x++;
	while ((temp[x] == ' ' || temp[x] == '\t') && temp[x])
		x++;
	if (!temp[x])
	{
		x--;
		while (temp[x] != ' ' && temp[x] != '\t' && x > 0)
			x--;
		x++;
	}
	(*i) = x;
	position_cursor((*i), con);
}

int			move_word(int act, int *i, char *temp, t_con *con)
{
	if (act == KEY_CTRL_LEFT)
		move_left(i, temp, con);
	else
		move_right(i, temp, con);
	return (1);
}
