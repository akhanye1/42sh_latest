/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhanye <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 11:36:52 by akhanye           #+#    #+#             */
/*   Updated: 2017/06/09 10:43:36 by akhanye          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	check_long(int digits, int ab, int num)
{
	if ((digits > 19) && (ab == 1))
		return (-1);
	else if ((digits > 19) && (ab == -1))
		return (0);
	return (ab * num);
}

int			ft_atoi(const char *nptr)
{
	int		num;
	int		i;
	int		ab;
	int		digits;

	ab = 1;
	digits = 0;
	i = ft_skipempty(nptr);
	if (nptr[i] == '-')
		ab = -1;
	num = 0;
	if (nptr[i] == '-' || nptr[i] == '+')
		i++;
	while ((nptr[i] != '\0') && (ft_isdigit(nptr[i]) != 0))
	{
		num = (num * 10) + (nptr[i] - '0');
		i++;
		digits++;
	}
	return (check_long(digits, ab, num));
}
