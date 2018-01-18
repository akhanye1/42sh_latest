/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter_out_redirections.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkgosise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 11:20:31 by mkgosise          #+#    #+#             */
/*   Updated: 2018/01/10 09:17:18 by skgatle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h_42sh.h"

static char	**get_filtered_args(char *cmd)
{
	struct s_get_filtered_args	st;

	st.args = ft_cmd_processor(cmd);
	if (!(st.ret = ft_listnew(1)))
		return (NULL);
	st.i = 0;
	while (st.args[st.i])
	{
		st.tmpstr = append_str(st.args[st.i]);
		if (is_close_std(st.tmpstr) || is_redirect_stdtostd(st.tmpstr))
			st.i++;
		else if (is_redirect(st.tmpstr))
			st.i += 2;
		else
		{
			st.tmp = ft_listcat(st.ret, st.args[st.i]);
			ft_free2d((void**)st.ret);
			st.ret = st.tmp;
			st.i++;
		}
		ft_strdel(&st.tmpstr);
	}
	ft_free2d((void**)st.args);
	return (st.ret);
}

char		**filter_out_redirections(char *cmd)
{
	char	**ret;
	char	*tmp;

	if (!(tmp = append_str(cmd)))
		return (NULL);
	if (!is_redirect(tmp) && !is_close_std(tmp) && !is_redirect_stdtostd(tmp))
	{
		ft_strdel(&tmp);
		return (ft_cmd_processor(cmd));
	}
	ret = get_filtered_args(tmp);
	ft_strdel(&tmp);
	if (!ret)
		return (NULL);
	return (ret);
}
