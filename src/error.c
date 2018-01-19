/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 09:02:39 by angonyam          #+#    #+#             */
/*   Updated: 2018/01/19 14:04:48 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h_42sh.h"

int			check_sides(char *str, char c)
{
	char	**sides;

	sides = ft_strsplit(str, c);
	if (!sides)
		return (-1);
	if (!sides[0] || !sides[1])
	{
		free_2d_array((void**)sides);
		return (-1);
	}
	else
		free_2d_array((void**)sides);
	return (1);
}

int			error_check(char *str)
{
	if (ft_strchr(str, ';'))
		return (check_sides(str, ';'));
	if (ft_strchr(str, '|'))
		return (check_sides(str, '|'));
	if (ft_strchr(str, '&'))
		return (check_sides(str, '&'));
	if (ft_strchr(str, '<'))
		return (check_sides(str, '<'));
	if (ft_strchr(str, '>'))
		return (check_sides(str, '>'));
	return (1);
}
