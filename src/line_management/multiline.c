#include "../h_42sh.h"

void	smart_right(int *i, t_con *con)
{
	char	buf[TERM_BUF];
	char	*ap;
	size_t	total_len;

	ap = buf;
	//clear_line(NULL, con);
	tputs(tgetstr("nd", &ap), 1, ft_puts);
	/*ft_putstr("Positions : (Screen Width) -> ");
	ft_putnbr(con->screen.width);
	ft_putstr(" Cursor Position -> ");
	ft_putnbr(*i + con->prompt_len);
	ft_putstr("\n");*/
	total_len = *i + con->prompt_len;
	if (total_len % con->screen.width == 0)
	{
		con->screen.add_y++;
		tputs(tgoto(tgetstr("cm", &ap), 0, con->screen.min_y
					+ con->screen.add_y), 1, ft_puts);
	}
}
