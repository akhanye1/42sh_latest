/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   suggestions_help.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhanye <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/07 16:01:46 by akhanye           #+#    #+#             */
/*   Updated: 2017/10/07 16:01:47 by akhanye          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h_42sh.h"

static char		fill_index(int ind)
{
	if (ind >= 0 && ind <= 25)
		return (ind + 97);
	else if (ind == 26)
		return (' ');
	else if (ind == 27)
		return ('.');
	else if (ind == 28)
		return ('%');
	else if (ind == 29)
		return ('-');
	else if (ind == 30)
		return ('_');
	else if (ind >= 31 && ind <= 40)
		return (ind + 17);
	return (-1);
}

static void		max_suggestion(t_tri *mem[2000], int *len,
					t_temp *local, t_tri **temp)
{
	mem[(*len)] = (*temp);
	local->suggest[(*len)++] = fill_index(local->i);
	local->suggest[*len] = '\0';
	(*temp) = (*temp)->letter[local->i];
	if ((*temp)->isword)
		suggestions(local->suggest, ADD, local->con, &(local->n));
}

void			find_suggestion(t_tri *mem[2000],
					t_tri **temp, int *len, t_temp *local)
{
	int i;

	i = -1;
	while (local->n < 40)
	{
		while (++i < 41)
		{
			if ((*temp)->letter[i])
			{
				local->i = i;
				max_suggestion(mem, len, local, temp);
				i = -1;
				break ;
			}
		}
		if (i >= 41)
		{
			(*temp) = mem[(*len) - 1];
			i = get_tri_index(local->suggest[(*len) - 1]);
			local->suggest[--(*len)] = '\0';
			if (!mem[*len])
				break ;
		}
	}
	suggestions(NULL, PRINT, local->con, &(local->n));
}
