/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkgosise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/23 16:43:39 by mkgosise          #+#    #+#             */
/*   Updated: 2017/07/29 13:35:07 by mkgosise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*clear_str(char *str)
{
	int		len;
	char	*ret;

	ret = ft_strdup(str);
	len = 63;
	str -= (len - ft_strlen(str));
	free(str);
	return (ret);
}

char		*ft_itoa_base(long val, int base)
{
	static char	rep[] = "0123456789abcdef";
	char		*ret;
	long long	num;

	ret = ft_strnew(64);
	ft_bzero((void*)ret, 64);
	if (base < 2 || base > 16)
		return (0);
	ret += 63;
	num = val;
	if (num < 0)
		num *= -1;
	if (num == 0)
		*--ret = rep[num % base];
	while (num != 0)
	{
		*--ret = rep[num % base];
		num /= base;
	}
	if (val < 0 && base == 10)
		*--ret = '-';
	return (clear_str(ret));
}
