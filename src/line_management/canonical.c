/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canonical.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhanye <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/08 11:32:16 by akhanye           #+#    #+#             */
/*   Updated: 2017/09/08 14:06:41 by akhanye          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h_42sh.h"

int		canonical_off(void)
{
	static struct termios	saveddata;
	static char				saved = 0;

	if (!saved)
	{
		tcgetattr(STDIN_FILENO, &saveddata);
		saved = 1;
	}
	return (tcsetattr(STDIN_FILENO, TCSANOW, &saveddata) != -1);
}

int		canonical_on(void)
{
	char					buff[TERM_BUF];
	static struct termios	edited;
	static char				saved = 0;

	if (!saved)
	{
		if (!isatty(STDIN_FILENO) || tgetent(buff, getenv("TERM")) <= 0 ||
				tcgetattr(0, &edited) == -1)
			return (0);
		edited.c_lflag &= ~(ICANON | ECHO);
		edited.c_cc[VMIN] = 1;
		edited.c_cc[VTIME] = 0;
		saved = 1;
		return (tcsetattr(STDIN_FILENO, TCSAFLUSH, &edited) != -1);
	}
	return (tcsetattr(STDIN_FILENO, TCSAFLUSH, &edited));
}

int		set_canonical(void)
{
	canonical_off();
	canonical_on();
	return (1);
}
