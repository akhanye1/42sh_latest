/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctrld_signal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhanye <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 07:00:48 by akhanye           #+#    #+#             */
/*   Updated: 2017/11/21 15:17:04 by akhanye          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h_42sh.h"

void	ctrld_signal(int *i, char *temp, t_con *con)
{
	int len;

	len = ft_strlen(temp);
	if (len > 0)
	{
		ft_bzero(temp, len);
		*i = 0;
		ft_putstr("\n$> ");
		clear_line(temp, con);
	}
	else
	{
		free_all(NULL);
		exit(0);
	}
}
