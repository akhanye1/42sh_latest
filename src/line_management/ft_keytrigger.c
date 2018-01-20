/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keytrigger.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhanye <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 10:27:40 by akhanye           #+#    #+#             */
/*   Updated: 2018/01/20 10:19:58 by akhanye          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h_42sh.h"

static int		get_all_digits(char *buff)
{
	int		len;
	int		i;
	char	num;

	len = 0;
	i = -1;
	while (buff[++i])
	{
		num = buff[i];
		while (num > 0)
		{
			len++;
			num /= 10;
		}
	}
	len--;
	return (len);
}

static int		get_value(char *buff)
{
	int		i;
	int		c;
	char	str[50];
	char	*temp;

	temp = ft_strdup(buff);
	i = -1;
	c = get_all_digits(buff);
	ft_bzero(str, 50);
	while (temp[++i])
		;
	while (i-- > 0)
	{
		while (temp[i] > 0)
		{
			str[c--] = (temp[i] % 10) + '0';
			temp[i] /= 10;
		}
	}
	free(temp);
	return (ft_atoi(str));
}

void			reset_line(t_con *con)
{
	static t_con	*saved = NULL;

	if (con)
	{
		saved = con;
		return ;
	}
	if (!saved)
		return ;
	if (saved->temp)
		ft_bzero(saved->temp, ft_strlen(saved->temp));
	saved->index = 0;
	clear_line(saved->temp, saved);
	end_key(&(saved->index), ft_strlen(saved->temp), saved);
}

static void		get_keyed(char *buf)
{
	int len;

	ft_bzero(buf, 7);
	len = read(0, buf, 7);
	buf[len] = '\0';
}

int				get_key_line(char **line, t_con *con)
{
	char	buf[7];
	int		key;

	con->index = 0;
	ft_bzero(con->temp, MAXWDIR);
	reset_line(con);
	ctrlc_signal(&(con->temp), &con);
	get_y_pos(&(con->screen), 1);
	while (1)
	{
		get_keyed(buf);
		if ((key = get_value(buf)) == 10)
			break ;
		k_action(key, con);
	}
	con->screen.add_y = 0;
	if (key == KEY_ENTER)
		check_line(con, line);
	return (1);
}
