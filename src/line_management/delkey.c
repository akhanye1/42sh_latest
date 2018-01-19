/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delkey.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhanye <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 11:15:15 by akhanye           #+#    #+#             */
/*   Updated: 2018/01/19 11:54:58 by akhanye          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h_42sh.h"

void		del_left(char *temp, int *i, t_con *con)
{
	char	*copy;

	if (!temp[*i])
	{
		temp[*i - 1] = '\0';
		clear_line(temp, con);
		end_key(i, ft_strlen(temp), con);
	}
	else
	{
		copy = temp + (*i);
		ft_strcpy(temp + (*i - 1), copy);
		clear_line(temp, con);
		move_cursor('l', i, NULL, con);
	}
}

void		del_right(char *temp, int *i, t_con *con)
{
	char	*copy;

	if (temp[*i])
	{
		copy = temp + (*i + 1);
		ft_strcpy(temp + *i, copy);
	}
	clear_line(temp, con);
}
