/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clipboard.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhanye <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/08 10:13:43 by akhanye           #+#    #+#             */
/*   Updated: 2017/09/08 14:58:50 by akhanye          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h_42sh.h"

void	copy_to_clipboard(t_con *con, int *ind, char *temp)
{
	int		dif;
	char	*cp;

	dif = (ind[1] - ind[0]) + 1;
	if (dif <= 1)
		return ;
	if (!con->clipboard)
		free(con->clipboard);
	if (!(cp = ft_strnew(dif + 1)))
		return ;
	ft_strncpy(cp, temp + ind[0], dif - 1);
	con->clipboard = cp;
	ind[0] = -1;
	ind[1] = -1;
	clear_line(temp, con);
}

void	paste_clipboard(t_con *con, int *i, char *temp)
{
	char	copy[MAXWDIR];

	if (!(con->clipboard))
		return ;
	ft_strcpy(copy, temp + *i);
	ft_bzero(temp + *i, ft_strlen(temp));
	ft_strcat(temp, con->clipboard);
	ft_strcat(temp, copy);
	clear_line(temp, con);
}
