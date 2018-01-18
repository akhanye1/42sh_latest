/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision_pf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkgosise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/24 16:44:40 by mkgosise          #+#    #+#             */
/*   Updated: 2017/07/27 11:14:26 by mkgosise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*dopadd(char *str, int size)
{
	char *ret;

	if (size > 0)
	{
		if ((int)ft_strlen(str) < ft_abs(size))
		{
			ret = ft_strnew(ft_abs(size));
			ft_memset(ret, ' ', (ft_abs(size) - ft_strlen(str)));
			ret += (ft_abs(size) - ft_strlen(str));
			ft_strcpy(ret, str);
			ret -= (ft_abs(size) - ft_strlen(str));
			str = ret;
		}
	}
	else
	{
		if ((int)ft_strlen(str) < ft_abs(size))
		{
			ret = ft_strnew(ft_abs(size));
			ft_memset(ret, ' ', ft_abs(size));
			ft_strncpy(ret, str, ft_strlen(str));
			str = ret;
		}
	}
	return (str);
}

static char	*doword(char *str, char convchr, int word, int padd)
{
	char *ret;

	if (word < (int)ft_strlen(str) && convchr != 'c' && convchr != 'C'
			&& convchr != 'i' && convchr != 'd' && convchr != 'D'
			&& convchr != 'x' && convchr != 'X' && convchr != 'u'
			&& convchr != 'U' && convchr != 'o' && convchr != 'O')
	{
		ret = ft_strnew(word);
		ft_bzero((void*)ret, word);
		ft_strncpy(ret, str, word);
		str = ret;
	}
	str = dopadd(str, padd);
	return (str);
}

char		*precision(char *conv, char *argstr)
{
	int		nbr;
	char	*tmp;
	char	**prec;

	tmp = ft_strsub(conv, 1, (ft_strlen(conv) - 2));
	prec = ft_strsplit(tmp, '.');
	free(tmp);
	if (countlist(prec) == 1)
	{
		tmp = dopadd(argstr, ft_atoi(prec[0]));
		argstr = tmp;
		ft_free2d((void**)prec);
	}
	else if (countlist(prec) == 2)
	{
		nbr = ft_atoi(prec[1]);
		tmp = doword(argstr, lastchar(conv), nbr, ft_atoi(prec[0]));
		argstr = tmp;
		ft_free2d((void**)prec);
	}
	return (argstr);
}
