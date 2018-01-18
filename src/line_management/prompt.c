/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhanye <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/01 08:51:46 by akhanye           #+#    #+#             */
/*   Updated: 2018/01/18 13:56:42 by akhanye          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h_42sh.h"

void	remove_below(void)
{
	char	buf[TERM_BUF];
	char	*ap;

	ft_bzero(buf, TERM_BUF);
	ap = buf;
	tputs(tgetstr("cd", &ap), 1, ft_puts);
}

int		temp_failure(char **line, t_con *con)
{
	print_prompt(con);
	return (get_key_line(line, con));
}

static void print_subshell(char *prompt, int num)
{
	int	len;

	ft_strcpy(prompt, "subsh ");
	num--;
	while (num--)
		ft_strcat(prompt, "subsh ");
	len = ft_strlen(prompt);
	prompt[len - 1] = '>';
	//ft_strcat(prompt, "> ");
}

void	print_prompt(t_con *con)
{
	char	prompt[100];

	ft_bzero(prompt, 100);
	if (!con->closequote)
		ft_strcpy(prompt, "dquote> ");
	else if (!con->morelines)
		ft_strcpy(prompt, "> ");
	else if (con->subshell)
		print_subshell(prompt, con->subshell);
	else
		ft_strcpy(prompt, "$> ");
	ft_putstr(prompt);
	con->prompt_len = ft_strlen(prompt);
}
