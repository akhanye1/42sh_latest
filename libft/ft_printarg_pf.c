/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printarg_pf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkgosise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/24 06:07:50 by mkgosise          #+#    #+#             */
/*   Updated: 2017/06/28 14:42:21 by mkgosise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	strtoupper(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		str[i] = ft_toupper(str[i]);
		i++;
	}
}

char		*printint(char *conv, int arg)
{
	char *ret;
	char lstchr;

	ret = NULL;
	lstchr = lastchar(conv);
	if (lstchr == 'i' || lstchr == 'd' || lstchr == 'D' ||
			lstchr == 'u' || lstchr == 'U')
		ret = ft_itoa(arg);
	else if (lstchr == 'o' || lstchr == 'O')
		ret = ft_itoa_base(arg, 8);
	else if (lstchr == 'x' || lstchr == 'X')
	{
		if (lstchr == 'X')
		{
			ret = ft_itoa_base(arg, 16);
			strtoupper(ret);
		}
		else
			ret = ft_itoa_base(arg, 16);
	}
	else if (lstchr == 'c' || lstchr == 'C')
		ret = chartostr(arg);
	ret = precision(conv, ret);
	return (ret);
}

char		*printstr(char *conv, char *arg)
{
	arg = precision(conv, arg);
	return (arg);
}

char		*printstrw(char *conv, wchar_t *arg)
{
	int		i;
	char	*str;

	i = 0;
	while (*arg++)
		i++;
	arg -= i + 1;
	str = ft_strnew(i);
	while (i != -1)
	{
		str[i] = arg[i];
		i--;
	}
	str = precision(conv, str);
	return (str);
}

char		*printpers(char *conv)
{
	return (precision(conv, chartostr('%')));
}
