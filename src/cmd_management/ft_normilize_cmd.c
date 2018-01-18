/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_normilize_cmd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmbotho <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/05 17:39:39 by nmbotho           #+#    #+#             */
/*   Updated: 2017/09/15 11:03:41 by nmbotho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h_42sh.h"
#define NEXT_SPACE (ft_isspace(cmd[*i + 1]))
#define NEXT_DIGIT (ft_isdigit(cmd[*i + 1]))
#define NEXT_OPCHAR (ft_is_opchar(cmd[*i + 1]))

int		ft_is_opchar(int c)
{
	if (c == '|' || c == '>' || c == '<' || c == '&')
		return (1);
	return (0);
}

void	opchar_handler(char *cmd, char *new, int *i, int *j)
{
	new[*j] = cmd[*i];
	(*j)++;
	if (cmd[*i] == '&')
	{
		if (!NEXT_OPCHAR && !NEXT_DIGIT && !NEXT_SPACE && cmd[*i + 1] != '-')
		{
			new[*j] = ' ';
			(*j)++;
		}
	}
	else if (!NEXT_OPCHAR && !NEXT_DIGIT && !NEXT_SPACE)
		new[(*j)++] = ' ';
}

void	copy_untill_char(char *cmd, char *new, t_iters *ij, char c)
{
	int i;
	int j;

	i = *(ij->i);
	j = *(ij->j);
	new[j] = cmd[i];
	i++;
	j++;
	while (cmd[i] != c && cmd[i])
	{
		new[j] = cmd[i];
		i++;
		j++;
	}
	new[j] = cmd[i];
	j++;
	if (ft_is_opchar(cmd[i + 1]))
		new[j++] = ' ';
	*(ij->i) = i;
	*(ij->j) = j;
}

void	basic_input(char *cmd, char *new, int i, int *j_ptr)
{
	int j;

	j = *j_ptr;
	if (ft_isdigit(cmd[i]))
		new[j++] = cmd[i];
	else if (!ft_isspace(cmd[i]))
	{
		new[j++] = cmd[i];
		if (ft_is_opchar(cmd[i + 1]))
			new[j++] = ' ';
	}
	*j_ptr = j;
}

char	*ft_normmilize_cmd(char *cmd)
{
	int		i;
	int		j;
	t_iters ij;
	char	*new;

	i = 0;
	j = 0;
	ij.i = &i;
	ij.j = &j;
	new = ft_strnew(4096);
	while (cmd[i])
	{
		if (ft_is_opchar(cmd[i]))
			opchar_handler(cmd, new, &i, &j);
		else if (cmd[i] == '\"')
			copy_untill_char(cmd, new, &ij, '\"');
		else if (ft_isspace(cmd[i]) && !ft_isspace(cmd[i + 1]) && j)
			new[j++] = ' ';
		else
			basic_input(cmd, new, i, &j);
		i++;
	}
	new[j] = '\0';
	return (new);
}
