/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkgosise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 10:07:13 by mkgosise          #+#    #+#             */
/*   Updated: 2017/07/08 11:31:00 by mkgosise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int i;
	int n;
	int nev;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
			|| str[i] == '\f' || str[i] == '\v' || str[i] == '\r')
		i++;
	nev = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			nev = -1;
		i++;
	}
	n = 0;
	while ((str[i] >= '0' && str[i] <= '9') && str[i] != '\0')
	{
		n = n * 10;
		n = n + ((int)str[i] - '0');
		i++;
	}
	return (n * nev);
}
