/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_history.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhanye <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 10:02:30 by akhanye           #+#    #+#             */
/*   Updated: 2018/01/17 09:21:07 by akhanye          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h_42sh.h"

static char	*move_history(t_history **temp, char dire)
{
	if (dire == 'u')
	{
		if ((*temp)->prev)
			(*temp) = (*temp)->prev;
	}
	else if (dire == 'd')
	{
		if ((*temp)->next)
			(*temp) = (*temp)->next;
		else
			return (NULL);
	}
	return ((*temp)->name);
}

char		*get_history(t_history **head, char dire)
{
	static t_history	*temp = NULL;
	static char			*scmd = NULL;

	if (head)
	{
		temp = (*head);
		scmd = NULL;
		return ("");
	}
	if (!temp)
		return ("");
	if (!scmd && dire == 'u')
	{
		scmd = temp->name;
		return (scmd);
	}
	scmd = move_history(&temp, dire);
	return (!scmd) ? "" : scmd;
}

void		add_to_history(t_history **head, char *line)
{
	t_history	*temp;
	static int	index = 1;

	if (!(temp = (t_history*)malloc(sizeof(t_history))))
		return ;
	temp->name = line;
	temp->num = index++;
	temp->next = NULL;
	temp->prev = NULL;
	if (!(*head))
		(*head) = temp;
	else
	{
		temp->prev = (*head);
		(*head)->next = temp;
		(*head) = temp;
	}
}

void		add_history(char **line, t_con *con)
{
	(*line) = ft_strtrim(con->temp);
	if (ft_strlen((*line)))
		add_to_history(&(con->history), (*line));
	get_history(&(con->history), 'r');
}
