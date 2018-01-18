/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_history.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhanye <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 10:04:43 by akhanye           #+#    #+#             */
/*   Updated: 2017/11/07 10:06:50 by akhanye          ###   ########.fr       */
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
