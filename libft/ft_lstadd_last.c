/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_last.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmbotho <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/29 15:47:08 by nmbotho           #+#    #+#             */
/*   Updated: 2017/07/29 15:47:19 by nmbotho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_last(t_list **alst, t_list *link)
{
	t_list	*current;

	current = *alst;
	if (*alst)
	{
		while (current->next)
			current = current->next;
		current->next = link;
	}
	else
		*alst = link;
}
