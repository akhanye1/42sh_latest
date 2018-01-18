/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_all.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skgatle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 09:15:33 by skgatle           #+#    #+#             */
/*   Updated: 2018/01/10 10:01:52 by skgatle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h_42sh.h"

int			ft_initialize_signals(char type)
{
	if (type == 'm')
	{
		signal(SIGINT, handle_main);
		signal(SIGQUIT, handle_main);
		signal(SIGTSTP, handle_main);
	}
	else if (type == 'p')
		signal(SIGINT, ft_handle_all);
	return (1);
}

int			ft_putchar_f(int c)
{
	write(2, &c, 1);
	return (1);
}

void		ft_handle_all(int sig)
{
	if (sig == SIGINT)
		ft_putchar('\n');
	signal(SIGINT, ft_handle_all);
}

void		ft_handle_psignal(int sig)
{
	if (sig == SIGINT)
	{
	}
}

void		handle_main(int sig)
{
	if (sig == SIGINT)
	{
		ctrlc_signal(NULL, NULL);
		signal(SIGINT, handle_main);
	}
	else if (sig == SIGQUIT)
		signal(SIGQUIT, handle_main);
	else if (sig == SIGTSTP)
		signal(SIGTSTP, handle_main);
}
