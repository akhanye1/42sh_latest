/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctrld_signal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhanye <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 07:00:48 by akhanye           #+#    #+#             */
/*   Updated: 2017/11/21 18:04:32 by akhanye          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h_42sh.h"

void	ctrlc_signal(char **line, t_con **con_set)
{
	static char		**str = NULL;
	static t_con	**con = NULL;
	int				l;

	canonical_off();
	canonical_on();
	if (line || con_set)
	{
		str = line;
		con = con_set;
		return ;
	}
	if (!*str || !*con)
		return ;
	if ((l = ft_strlen(*str)) > 0)
		ft_bzero(*str, l);
	ft_putstr("\n");
	print_prompt(*con);
	get_y_pos(&((*con)->screen), 1);
}
