/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_findconv_pf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkgosise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/24 05:45:34 by mkgosise          #+#    #+#             */
/*   Updated: 2017/07/27 10:29:28 by mkgosise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	convend(const char *frmt)
{
	int		i;
	int		convlen;
	char	*conv;

	i = 0;
	conv = "sSpdDioOuUxXcC%";
	convlen = ft_strlen(conv);
	while (*frmt++)
	{
		i++;
		while (*conv)
		{
			if (*conv == *frmt)
				return (i);
			conv++;
		}
		conv -= convlen;
	}
	return (i);
}

char		*findconv(const char *frmt)
{
	int		i;
	char	*conv;
	char	*ret;
	char	*tmp;

	i = 0;
	ret = ft_strnew(1);
	ft_bzero((void*)ret, 1);
	while (frmt[i])
	{
		if (frmt[i] == '%')
		{
			conv = ft_strsub(frmt, i, (convend(&frmt[i]) + 2));
			conv[ft_strlen(conv) - 1] = '?';
			tmp = ft_strjoin(ret, conv);
			frmt += ft_strlen(conv);
			free(ret);
			free(conv);
			ret = tmp;
		}
		i++;
	}
	return (ret);
}
