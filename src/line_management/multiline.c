/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiline.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhanye <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 08:52:02 by akhanye           #+#    #+#             */
/*   Updated: 2018/01/19 09:05:15 by akhanye          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h_42sh.h"

void	smart_right(int *i, t_con *con)
{
	char	buf[TERM_BUF];
	char	*ap;
	size_t	total_len;

	ap = buf;
	tputs(tgetstr("nd", &ap), 1, ft_puts);
	total_len = *i + con->prompt_len;
	if (total_len % con->screen.width == 0)
	{
		if (ft_strlen(con->temp) <= (size_t)*i)
			con->screen.add_y++;
		tputs(tgoto(tgetstr("cm", &ap), 0, con->screen.min_y
					+ con->screen.add_y), 1, ft_puts);
	}
}
