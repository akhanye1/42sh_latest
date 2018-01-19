/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cursor.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhanye <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 10:26:08 by akhanye           #+#    #+#             */
/*   Updated: 2017/12/12 09:38:55 by akhanye          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h_42sh.h"

void	clear_line(char *str, t_con *con)
{
	char		buf[TERM_BUF];
	char		*ap;
	char		*temp;
	static char	*s_str = NULL;

	temp = str;
	if (str)
		s_str = str;
	else
		temp = s_str;
	ft_bzero(buf, TERM_BUF);
	ap = buf;
	tputs(tgetstr("sc", &ap), 1, ft_puts);
	tputs(tgoto(tgetstr("cm", &ap), 0, con->screen.min_y), 1, ft_puts);
	tputs(tgetstr("cd", &ap), 1, ft_puts);
	print_prompt(con);
	if (temp)
		ft_putstr(temp);
	tputs(tgetstr("rc", &ap), 1, ft_puts);
	copy_selection('e', NULL, NULL, NULL);
	search(NULL, NULL, con);
}

void	move_cursor(char dir, int *i, t_con *con, t_con *head)
{
	char	buf[TERM_BUF];
	char	*ap;

	ap = buf;
	if (con)
		clear_line(NULL, con);
	(*i) = (dir == 'l') ? (*i) - 1 : (*i) + 1;
	if (dir == 'l')
		tputs(tgetstr("le", &ap), 1, ft_puts);
	else if (dir == 'r')
		//tputs(tgetstr("nd", &ap), 1, ft_puts);
		smart_right(i, head);
}

void	home_key(int *i, t_con *con)
{
	char	buf[TERM_BUF];
	char	*ap;

	ft_bzero(buf, TERM_BUF);
	ap = buf;
	tputs(tgoto(tgetstr("cm", &ap), 3, con->screen.min_y), 1, ft_puts);
	(*i) = 0;
}

void	end_key(int *i, int str_len, t_con *con)
{
	char	buf[TERM_BUF];
	char	*ap;

	ft_bzero(buf, TERM_BUF);
	ap = buf;
	tputs(tgoto(tgetstr("cm", &ap), 3 + str_len,
				con->screen.min_y), 1, ft_puts);
	(*i) = str_len;
}

void	find_history(char dir, int *i, char *temp, t_con *con)
{
	char	*dmp;
	int		len;

	len = ft_strlen(temp);
	ft_bzero(temp, len);
	dmp = get_history(NULL, dir);
	ft_strcpy(temp, dmp);
	clear_line(temp, con);
	end_key(i, ft_strlen(temp), con);
}
