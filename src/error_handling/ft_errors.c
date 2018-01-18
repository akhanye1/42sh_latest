/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmbotho <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/10 10:52:05 by nmbotho           #+#    #+#             */
/*   Updated: 2017/09/10 10:52:13 by nmbotho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h_42sh.h"

void	ft_error(char *message)
{
	ft_putstr_fd("42sh: ", 2);
	ft_putendl_fd(message, 2);
}

void	ft_cmderror(char *message, char *arg)
{
	ft_putstr_fd("42sh: ", 2);
	ft_putstr_fd(message, 2);
	ft_putstr_fd(": ", 2);
	ft_putendl_fd(arg, 2);
}
