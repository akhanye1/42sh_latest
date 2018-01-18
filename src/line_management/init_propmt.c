/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_propmt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhanye <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/01 08:51:31 by akhanye           #+#    #+#             */
/*   Updated: 2018/01/17 11:17:55 by akhanye          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h_42sh.h"

void		init_prompt(t_con *con)
{
	con->clipboard = NULL;
	con->trisearch = NULL;
	con->history = NULL;
	con->multiline = NULL;
	con->shellcommands = NULL;
	con->temp = ft_strnew(MAXWDIR);
	con->closequote = 1;
	con->index = 0;
	con->morecommands = NULL;
	con->morelines = 1;
	con->subshell = 0;
}
