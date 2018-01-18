/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchaction.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhanye <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/01 08:53:30 by akhanye           #+#    #+#             */
/*   Updated: 2017/11/07 09:36:35 by akhanye          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h_42sh.h"

void		position_x_cursor(int x, int y)
{
	char	buf[TERM_BUF];
	char	*ap;

	ft_bzero(buf, TERM_BUF);
	ap = buf;
	tputs(tgoto(tgetstr("cm", &ap), x,
				y), 1, ft_puts);
}

void		show_suggestion(char *str, t_con *con)
{
	char	buf[TERM_BUF];
	char	*ap;

	get_y_pos(&(con->screen), 0);
	ft_bzero(buf, TERM_BUF);
	ap = buf;
	tputs(tgoto(tgetstr("cm", &ap), 0,
				con->screen.min_y), 1, ft_puts);
	tputs(tgetstr("ce", &ap), 1, ft_puts);
	ft_putstr("$> ");
	if (str)
	{
		ft_putstr(str);
		con->index = ft_strlen(str);
		end_key(&(con->index), ft_strlen(str), con);
	}
}

static void	scrollup(int ypos, int *y)
{
	char	buf[TERM_BUF];
	char	*ap;

	position_x_cursor(0, ypos);
	ap = buf;
	tputs(tgetstr("sf", &ap), 1, ft_puts);
	(*y)--;
}

void		put_words(int maxlen, t_con *con, char wrds[42][MAXWDIR])
{
	int col;
	int col1;
	int ypos;
	int i;
	int y;

	col = con->screen.width / maxlen;
	ypos = con->screen.min_y;
	y = ypos + 1;
	i = 0;
	while (ft_strlen(wrds[i]))
	{
		col1 = 0;
		if (y >= (int)con->screen.height)
			scrollup(y, &ypos);
		while (col1 < col && ft_strlen(wrds[i]))
		{
			position_x_cursor(col1 * maxlen, y);
			ft_putstr(wrds[i++]);
			col1++;
		}
		y++;
	}
	con->screen.min_y = ypos;
	position_x_cursor(0, ypos);
}

void		show_usr_suggestions(char wrds[42][MAXWDIR], t_con *con)
{
	int	maxlen;
	int	i;

	get_y_pos(&(con->screen), 0);
	i = -1;
	maxlen = 0;
	while (ft_strlen(wrds[++i]))
		maxlen = ((int)ft_strlen(wrds[i]) > maxlen) ?
			ft_strlen(wrds[i]) : maxlen;
	maxlen += 2;
	put_words(maxlen, con, wrds);
}
