# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkgosise <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/31 15:02:02 by mkgosise          #+#    #+#              #
#    Updated: 2017/09/11 17:51:13 by mkgosise         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_atoi.c				ft_bzero.c		ft_isalnum.c	ft_isalpha.c\
	  ft_isascii.c			ft_isdigit.c	ft_isprint.c	ft_memccpy.c\
	  ft_memchr.c			ft_memcmp.c		ft_memcpy.c		ft_memmove.c\
	  ft_memset.c			ft_strcat.c		ft_strchr.c		ft_strcmp.c\
	  ft_strcpy.c			ft_strdup.c		ft_strlcat.c	ft_strlen.c\
	  ft_strncat.c			ft_strncmp.c	ft_strncpy.c	ft_strrchr.c\
	  ft_strnstr.c			ft_strstr.c		ft_tolower.c	ft_toupper.c\
	  ft_putstr.c			ft_putchar.c	ft_putnbr.c		ft_memalloc.c\
	  ft_memdel.c			ft_strclr.c		ft_striter.c	ft_striteri.c\
	  ft_strmap.c			ft_strmapi.c	ft_strequ.c		ft_strsub.c\
	  ft_strjoin.c			ft_strtrim.c	ft_strsplit.c	ft_putstr_fd.c\
	  ft_strdel.c			ft_strnew.c		ft_putendl.c	ft_putchar_fd.c\
	  ft_itoa.c				ft_putendl_fd.c	ft_putnbr_fd.c	ft_strnequ.c\
	  ft_abs.c				ft_itoa_base.c	ft_printf.c		ft_findconv_pf.c\
	  ft_lastchar_pf.c						ft_countlist_pf.c\
	  ft_strdupadd_pf.c						ft_chartostr_pf.c\
	  ft_printarg_pf.c						ft_precision_pf.c\
	  ft_sort.c				ft_locchr.c		ft_strjoinpath.c\
	  ft_sort_2d.c			ft_getin.c		ft_listcat.c	ft_updatelist.c\
	  ft_free2d.c			ft_listdup.c	ft_item_listcmp.c\
	  ft_putcolor.c			ft_listnew.c	ft_list_del_el.c ft_remove_elem.c\
	  ft_isspace.c			ft_count2d.c	get_next_line.c	ft_strsplit_2.c\
	  ft_strlentochar.c  	ft_lstadd_last_d.c 	ft_lst_to_2dstring.c\
	  ft_lst_count.c ft_lstdel.c ft_del.c ft_lstdelone.c  ft_strpos.c\
	  ft_strrpos.c

OBJ = $(SRC:%.c=%.o)

INCLUDES = libft.h

FLAGS = -Wall\
		-Wextra\
		-Werror

all: $(NAME)

$(NAME):
	@gcc -c $(FLAGS) $(INCLUDES) $(SRC)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

clean:
	@rm -f $(OBJ)
	@rm -f libft.h.gch

fclean: clean
	@rm -f $(NAME)

re: fclean all

