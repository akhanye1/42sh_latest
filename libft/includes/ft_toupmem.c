/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhanye <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 11:28:44 by akhanye           #+#    #+#             */
/*   Updated: 2017/06/02 22:05:08 by akhanye          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_toupmem(unsigned int c, char *s)
{
	int diff;

	diff = 'a' - 'A';
	if (s[c] >= 'a' && s[c] <= 'z')
		ft_putchar(s[c] - diff);
	else
		ft_putchar(s[c]);
}
