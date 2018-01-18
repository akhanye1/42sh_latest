/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkgosise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 14:43:24 by mkgosise          #+#    #+#             */
/*   Updated: 2017/09/11 13:01:38 by mkgosise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

# define BUFF_SIZE 32

typedef char*		t_string;
typedef const char*	t_const;

typedef	struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putnbr(int n);
void				ft_bzero(void *s, size_t n);
void				ft_memdel(void **ap);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
void				ft_putendl(char const *s);
void				ft_strdel(char **as);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				*ft_memchr(const void *s, int c, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memset(void *b, int c, size_t len);
void				*ft_memalloc(size_t size);
void				ft_sort(char *str);
void				ft_free2d(void **arr);
void				ft_putcolor(char *color);

int					ft_atoi(const char *str);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
int					ft_isspace(int c);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_tolower(int c);
int					ft_toupper(int c);
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
int					ft_abs(int nbr);
int					countlist(char **list);
int					ft_printf(const char *format, ...);
int					ft_locchr(char *str, char c);
int					ft_updatelist(char **arr, char *find, char *src);
int					ft_list_del_el(char **list, char *el);

size_t				ft_strlen(const char *str);
size_t				ft_strlcat(char *dst, const char *src, size_t size);

char				lastchar(char *str);

char				*ft_strcat(char *s1, const char *s2);
char				*ft_strchr(const char *s, int c);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncat(char *s1, const char *s2, size_t n);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strnstr(const char *big, const char *little, size_t l);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *big, const char *little);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				*ft_itoa(int n);
char				*ft_strnew(size_t size);
char				*ft_strdup(const char *s1);
char				*ft_itoa_base(long val, int base);
char				*findconv(const char *frmt);
char				*strdupadd(const char *str);
char				*chartostr(char c);
char				*printint(char *conv, int arg);
char				*printstr(char *conv, char *arg);
char				*printstrw(char *conv, wchar_t *arg);
char				*printpers(char *conv);
char				*precision(char *conv, char *argstr);
char				*ft_strjoinpath(char const *s1, char const *s2);
char				*getin(void);
char				**ft_strsplit(char const *s, char c);
char				**ft_sort_2d(char **arr);
char				**ft_sort_2d_on(char **arr, char **on);
char				**ft_listcat(char **list, char *str);
char				**ft_listdup(char **list);
char				**ft_listnew(int size);
char				**ft_strsplit_2(char const *s);
void				ft_remove_elem(char **array, int index);
int					ft_count2d(void **array);
int					get_next_line(const int fd, char **line);
void				ft_free2dsafe(void ***arr);
int					ft_strlentochar(char *s, int c);
int					ft_lst_count(t_list *list);
void				ft_lstadd_last_d(t_list **alst, void *cont, size_t size);
t_string			*ft_lst_to_2dstring(t_list **list);
void				ft_lstdel(t_list **alst, void(*del)(void*, size_t));
void				ft_lstadd_last(t_list **alst, t_list *link);
void				ft_del(void *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void(*del)(void *, size_t));
int					ft_strpos(const char *s, int c);
int					ft_strrpos(const char *s, int c);

#endif
