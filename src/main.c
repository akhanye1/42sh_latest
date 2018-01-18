/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkgosise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/30 11:50:09 by mkgosise          #+#    #+#             */
/*   Updated: 2018/01/17 10:13:52 by akhanye          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h_42sh.h"

t_con	*ft_get_con(void)
{
	static t_con	*con;

	con = (t_con *)malloc(sizeof(t_con));
	return (con);
}

int		main(void)
{
	char	*line;
	t_con	*con;
	int		empty;

	con = ft_get_con();
	set_canonical();
	init_prompt(con);
	init_screen(con);
	init_autocomplete(con);
	while (TRUE)
	{
		ft_initialize_signals('m');
		print_prompt(con);
		get_key_line(&line, con);
		if (ft_strstr(line, "&&") || ft_strstr(line, "||"))
			andor_management(line, ft_get_environ(), &empty);
		else
			ft_split_cmd(line);
	}
	canonical_off();
	return (0);
}
