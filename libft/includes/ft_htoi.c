/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhanye <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 11:36:52 by akhanye           #+#    #+#             */
/*   Updated: 2017/07/02 01:44:13 by akhanye          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	get_num(const char *nptr, int i)
{
	int num;
	int l;

	num = 1;
	while (nptr[i] != '\0')
	{
		if ((ft_tolower(nptr[i]) >= 'a' &&
					ft_tolower(nptr[i]) <= 'f') || ft_isdigit(nptr[i]) != 0)
		{
			if (ft_isalpha(ft_tolower(nptr[i])) != 0)
				l = (ft_tolower(nptr[i]) - 'a') + 10;
			else
				l = nptr[i] - '0';
			if (l == 0)
				l = 1;
		}
		num = num * l;
		i++;
	}
	return (num);
}

int			ft_htoi(const char *nptr)
{
	int		i;
	int		l;

	i = ft_skipempty(nptr);
	if (ft_strchr(nptr + i, 'x') != NULL || ft_strchr(nptr + i, 'X') != NULL)
	{
		if (ft_strchr(nptr + i, 'x') != NULL)
			l = ft_strchr(nptr + i, 'x') - nptr;
		else
			l = ft_strchr(nptr + i, 'X') - nptr;
		i += l;
	}
	return (get_num(nptr, i));
}
