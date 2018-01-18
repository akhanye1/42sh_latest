/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkgosise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 13:54:22 by mkgosise          #+#    #+#             */
/*   Updated: 2018/01/10 11:17:31 by skgatle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h_42sh.h"

void	echo_handler(char **args)
{
	int i;

	i = 1;
	if (args[i])
		while (args[i])
		{
			ft_putstr(args[i]);
			if (args[i + 1])
				ft_putchar(' ');
			i++;
		}
	ft_putchar('\n');
}
