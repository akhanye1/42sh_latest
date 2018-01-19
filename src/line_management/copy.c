/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_copy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhanye <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/08 10:13:16 by akhanye           #+#    #+#             */
/*   Updated: 2017/09/08 14:55:41 by akhanye          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h_42sh.h"

static void	highlight(char pos)
{
	char	buf[TERM_BUF];
	char	*ap;

	ft_bzero(buf, TERM_BUF);
	ap = buf;
	if (pos)
		tputs(tgetstr("mr", &ap), 1, ft_puts);
	else
		tputs(tgetstr("me", &ap), 1, ft_puts);
}

static void	highlight_word(t_con *con, char *temp, int *ind)
{
	char	buf[TERM_BUF];
	char	*ap;
	int		n;

	ft_bzero(buf, TERM_BUF);
	ap = buf;
	tputs(tgetstr("sc", &ap), 1, ft_puts);
	tputs(tgoto(tgetstr("cm", &ap), 0, con->screen.min_y), 1, ft_puts);
	tputs(tgetstr("ce", &ap), 1, ft_puts);
	ft_putstr("$> ");
	n = -1;
	while (temp[++n] && n < ind[0])
		ft_putchar(temp[n]);
	n--;
	highlight(1);
	while (temp[++n] && n < ind[1])
		ft_putchar(temp[n]);
	n--;
	highlight(0);
	while (temp[++n])
		ft_putchar(temp[n]);
	tputs(tgetstr("rc", &ap), 1, ft_puts);
}

static void	copy_right(int *i, char *temp, t_con *con, int *ind)
{
	if (ind[0] == -1)
	{
		ind[0] = *i;
		ind[1] = *i + 1;
	}
	else
		ind[1] = *i + 1;
	highlight_word(con, temp, ind);
	move_cursor('r', i, NULL, con);
}

static void	copy_left(int *i, char *temp, t_con *con, int *ind)
{
	if (ind[1] == -1)
	{
		ind[0] = *i - 1;
		ind[1] = *i;
	}
	else if (*i > ind[0])
		ind[1] = *i - 1;
	else
		ind[0] = *i - 1;
	highlight_word(con, temp, ind);
	move_cursor('l', i, NULL, con);
}

void		copy_selection(int act, int *i, char *temp, t_con *con)
{
	static int	ind[2] = {-1, -1};

	if (!temp && !con && !i)
	{
		ind[0] = -1;
		ind[1] = -1;
		return ;
	}
	if (act == KEY_COPY_RIGHT)
		copy_right(i, temp, con, ind);
	else if (act == KEY_COPY_LEFT)
		copy_left(i, temp, con, ind);
	else if (act == KEY_COPY)
		copy_to_clipboard(con, ind, temp);
	else if (act == KEY_PASTE)
		paste_clipboard(con, i, temp);
}
