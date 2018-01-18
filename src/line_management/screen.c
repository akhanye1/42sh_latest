/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pos.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhanye <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 11:19:22 by akhanye           #+#    #+#             */
/*   Updated: 2017/09/08 14:42:58 by akhanye          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h_42sh.h"

void		get_y_pos(t_screen *screen, int x)
{
	int		a;
	int		i;
	char	buf[4];

	write(1, "\033[6n", 4);
	i = read(1, buf, 4);
	buf[i] = '\0';
	i = -1;
	a = 0;
	while (buf[++i])
	{
		if (buf[i] >= 48 && buf[i] <= 57)
		{
			if (a == 0)
				screen->min_y = ft_atoi(&buf[i]) - 1;
			else if (x)
				screen->min_x = ft_atoi(&buf[i]) - 1;
			a++;
		}
	}
}

void		init_screen(t_con *con)
{
	con->screen.width = tgetnum("co");
	con->screen.height = tgetnum("li");
	con->screen.mw_width = 0;
	con->screen.padding = 0;
	con->history = NULL;
	con->clipboard = NULL;
}
