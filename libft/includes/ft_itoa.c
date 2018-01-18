/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhanye <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/03 05:35:39 by akhanye           #+#    #+#             */
/*   Updated: 2017/06/09 10:44:45 by akhanye          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static void		convert(char *tmp, int digits, int n)
{
	int neg;

	neg = 1;
	digits--;
	tmp[digits] = '\0';
	digits--;
	if (n < 0)
	{
		neg = -1;
		tmp[0] = '-';
		if (n == -2147483648)
		{
			tmp[digits] = '8';
			digits--;
			n = 2147483640 / 10;
		}
		else
			n = -(n);
	}
	while ((digits >= 0 && neg == 1) || (digits > 0 && neg == -1))
	{
		tmp[digits] = (n % 10) + '0';
		n /= 10;
		digits--;
	}
}

char			*ft_itoa(int n)
{
	char	*tmp;
	int		digits;

	digits = ft_digits(n) + 1;
	if (n <= 0)
		digits++;
	tmp = (char*)malloc(sizeof(char) * digits);
	if (tmp == NULL)
		return (NULL);
	if (n == 0)
	{
		ft_strcpy(tmp, "0");
		return (tmp);
	}
	convert(tmp, digits, n);
	return (tmp);
}
