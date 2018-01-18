/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhanye <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 13:24:06 by akhanye           #+#    #+#             */
/*   Updated: 2017/06/05 16:50:34 by akhanye          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_lastal(const char *s)
{
	int				i;
	unsigned char	*c;
	int				da;

	c = (unsigned char *)s;
	i = (size_t)ft_strlen(s) - 1;
	da = 1;
	while (da == 1)
	{
		da = 0;
		while ((c[i] == ' ' || c[i] == '\t' || c[i] == '\n') && c[i] != '\0')
		{
			da = 1;
			i--;
		}
		while ((c[i] == '\v' || c[i] == '\f' || c[i] == '\r') && c[i] != '\0')
		{
			da = 1;
			i--;
		}
	}
	return (i);
}
