/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkgosise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/22 12:35:33 by mkgosise          #+#    #+#             */
/*   Updated: 2017/07/29 13:44:39 by mkgosise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**convlist(const char *format)
{
	char	*convstr;
	char	*tmp;
	char	**convlst;

	tmp = strdupadd(format);
	convstr = findconv(tmp);
	free(tmp);
	convlst = ft_strsplit(convstr, '?');
	free(convstr);
	return (convlst);
}

static int	printfinal(const char *format, char **convlst, char **argstr)
{
	int		ret;

	ret = 0;
	while (*argstr)
	{
		while (*format && *format != '%')
		{
			ft_putchar(*format++);
			ret++;
		}
		ft_putstr(*argstr);
		ret += ft_strlen(*argstr++);
		format += ft_strlen(*convlst++);
	}
	while (*format)
	{
		ft_putchar(*format++);
		ret++;
	}
	return (ret);
}

static int	isint(char c)
{
	char *conv;

	conv = "idDcCxXuUoO";
	while (*conv)
		if (*conv++ == c)
			return (1);
	return (0);
}

int			ft_printf(const char *format, ...)
{
	int		i;
	char	**convlst;
	char	**argstr;
	va_list	arg;

	i = 0;
	convlst = convlist(format);
	va_start(arg, format);
	argstr = (char**)malloc(sizeof(argstr) * (countlist(convlst) + 1));
	argstr[countlist(convlst)] = 0;
	while (convlst[i])
	{
		if (isint(lastchar(convlst[i])))
			argstr[i] = printint(convlst[i], va_arg(arg, int));
		else if (lastchar(convlst[i]) == 's')
			argstr[i] = printstr(convlst[i], va_arg(arg, char *));
		else if (lastchar(convlst[i]) == 'S')
			argstr[i] = printstrw(convlst[i], va_arg(arg, wchar_t *));
		else if (lastchar(convlst[i]) == '%')
			argstr[i] = printpers(convlst[i]);
		i++;
	}
	va_end(arg);
	return (printfinal(format, convlst, argstr));
}
