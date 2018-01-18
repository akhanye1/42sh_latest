/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_andor.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 09:47:15 by angonyam          #+#    #+#             */
/*   Updated: 2018/01/17 10:27:13 by akhanye          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h_42sh.h"

t_andor			*new_andor(char *str)
{
	t_andor		*new;

	new = (t_andor *)malloc(sizeof(t_andor));
	new->comm = ft_strdup(str);
	new->next = NULL;
	return (new);
}

t_andor			*add_andor(t_andor *head, char *str)
{
	t_andor		*trav;

	trav = head;
	while (trav->next)
		trav = trav->next;
	trav->next = (t_andor*)malloc(sizeof(t_andor));
	trav->next->comm = ft_strdup(str);
	trav->next->next = NULL;
	return (trav);
}

void			free_andor(t_andor *head)
{
	t_andor		*trav;

	while (head)
	{
		trav = head;
		head = head->next;
		free(trav->comm);
		free(trav);
	}
}

void			print_andor(t_andor *head)
{
	t_andor		*trav;

	trav = head;
	while (trav)
	{
		ft_putendl(trav->comm);
		trav = trav->next;
	}
}
