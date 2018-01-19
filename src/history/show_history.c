/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_history.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhanye <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 10:04:43 by akhanye           #+#    #+#             */
/*   Updated: 2018/01/19 12:01:14 by akhanye          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h_42sh.h"

void		show_history(t_con *con)
{
	t_history *temp;

	temp = con->history;
	if (!temp)
		return ;
	while (temp->prev)
		temp = temp->prev;
	while (temp)
	{
		ft_putnbr(temp->num);
		ft_putstr(" : ");
		ft_putendl(temp->name);
		temp = temp->next;
	}
	print_prompt(con);
}

int			history_command(char **line, t_con *con)
{
	show_history(con);
	return (get_key_line(line, con));
}
