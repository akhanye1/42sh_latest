/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkgosise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 14:28:47 by mkgosise          #+#    #+#             */
/*   Updated: 2017/06/25 17:01:54 by mkgosise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*isnav(int n, char *strn)
{
	char *ret;

	if (n < 0)
	{
		ret = ft_strnew(ft_strlen(strn) + 1);
		ft_bzero((void*)ret, ft_strlen(strn) + 1);
		ret[0] = '-';
		ft_strcpy(&ret[1], strn);
		return (ret);
	}
	return (strn);
}

char		*ft_itoa(int n)
{
	int		i;
	int		nbr;
	int		nav;
	char	*ret;

	i = 0;
	nav = n;
	n = ft_abs(n);
	nbr = n;
	while (nbr != 0)
	{
		nbr = nbr / 10;
		i++;
	}
	ret = (char*)ft_memalloc(i + 1);
	nbr = i;
	while (n != 0)
	{
		i--;
		ret[i] = 48 + (n % 10);
		n = n / 10;
	}
	ret[nbr] = '\0';
	return (isnav(nav, ret));
}
