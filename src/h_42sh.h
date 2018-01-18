/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   42sh.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkgosise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/30 11:52:33 by mkgosise          #+#    #+#             */
/*   Updated: 2018/01/18 17:49:48 by skgatle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef H_42SH_H
# define H_42SH_H

# include "../libft/libft.h"
# include <strings.h>
# include <stdlib.h>
# include <stdio.h>
# include <dirent.h>
# include <fcntl.h>
# include <termcap.h>
# include <signal.h>
# include <term.h>
# include <sys/wait.h>
# define TRUE 1
# define FALSE 0
# define TERM_BUF 30
# define MAXWDIR 10000
# define ARG_MAX 4096
# define BINARY_MAX 5381
//# define PATH_MAX 255
# define APPEND (info->append = TRUE)
# define PF (info->p_flag)
# define OUT_ND_IN (inf->fd[1] != 8 && inf->fd[0] != 1)

/*
** KEYS
*/

# define KEY_UP 279165
# define KEY_DOWN 279166
# define KEY_LEFT 279168
# define KEY_RIGHT 279167
# define KEY_SPACE 32
# define KEY_BACKSPACE 127
# define KEY_DEL 279151126
# define KEY_HOME 279172
# define KEY_END 279170
# define KEY_CTRL_LEFT -23278872
# define KEY_CTRL_RIGHT -23278873
# define KEY_ENTER 10
# define KEY_COPY_LEFT -23279172
# define KEY_COPY_RIGHT -23279173
# define KEY_COPY -23279175
# define KEY_PASTE -23279174
# define KEY_END_COPY -23279170
# define KEY_HOME_COPY -23279168
# define KEY_CTRL_D 4
# define KEY_TAB 9

/*
** ENVIRONMENT
*/

char				**ft_get_environ();
int					ft_setenv(char *key, char *value);
void				ft_unsetenv(char *variable);
char				*ft_getenv(char *key);
void				ft_unset_main(char **args);
void				ft_setenv_main(char **args);
void				ft_env(char **args);

/*
** ECHO
*/

void				echo_handler(char **args);

/*
** PIPES
*/

typedef int			t_bool;
typedef struct		s_pipe
{
	t_bool			p_last;
	t_bool			p_flag;
	t_bool			r_flag;
	t_bool			pip_red;
	t_bool			append;
	t_bool			red_err;
	t_bool			builtin;
	pid_t			pid_prev;
	t_bool			builtin_act;
	t_bool			exit_builtin;
	pid_t			pid_cur;
	int				fildes[2];
	int				fildes2[2];
	int				fd_in;
	int				redin;
	int				fd_red;
	int				fd_stdin;
	int				fd[3];
	int				cnt;
	char			*path;
	char			*cmd;
	char			*file;
	char			**arg;
}					t_pipe;

int					ft_handle_pipes(char **args);
t_pipe				*ft_pipe_flags(t_pipe *info, char operation);
int					ft_pipe_red(int in, int o, int e, t_pipe *i);
int					ft_initialize_pipes(int input, int output);
void				ft_execute_pipe_cmd(char *p_args, char **args,
		int in, int fd);
int					ft_pipe_recursive(char **p_args, int in, t_pipe *info);
int					ft_pipe_buildins(char *p_args, char **args, int in, int fd);
int					ft_buildins(char *cmd);
int					ft_save_to_file(t_pipe *i);
void				ft_append(char *buf[], t_pipe *inf);
void				ft_close_fds(t_pipe *inf, char type);
void				ft_check_for_error(int	ret);
int					ft_check_pips(t_pipe *info);
void				ft_setfd_for_tee(t_pipe *inf);
void				ft_setfd_for_main(t_pipe *inf);

/*
** BACKTICKS
*/

struct				s_run_cmd
{
	int				i;
	char			*tmp;
	char			*ret;
	char			*trim;
	char			**cmd;
};
struct				s_ready_backtick
{
	int				i;
	char			c;
	char			*tmp;
	char			*str;
	char			*join;
};

typedef struct		s_interators
{
	int				*i;
	int				*j;
}					t_iters;

char				*run_backticks_cmd(char *cmd, t_pipe *info);
int					backticks_handler(char **cmd, t_pipe *info);

/*
** LOCAL VARIABLES
*/

int					ft_keylen(char *pair);
char				**ft_get_locals();
char				*ft_getlocal(char *key);
int					ft_set_local(char *pair);
void				ft_unset_local(char *key);
void				ft_print_locals();
char				*ft_key_resolver(char *cmd, int *i);
char				*ft_dquote_handler(char *cmd, int *i);
char				**ft_resolve_args(char *cmd);
int					ft_set_local_main(char **args);
int					ft_unset_local_main(char **args);
void				ft_export(char **args);
int					ft_setenv_pair(char *pair);

/*
** GLOBBING
*/

int					index_of(char *s, int c);
int					box_match(char *glob, char *ref, int *i, int k);
int					box_range(char *glob, char *ref, int *i, int k);
int					box_handler(char *glob, char *ref, int *i, int *j);
int					main_test(char *glob, char *ref);
void				add_entries(char *glob, t_list **entries);
char				**resolve_globs(char **args);

/*
** SIGNALS
*/

void				handle_main(int sig);
int					ft_initialize_signals(char type);
void				ft_handle_all(int sig);
void				ft_handle_psignal(int sig);

/*
** SHARED FUNCTIONS
*/

char				*ft_full_path(char *cmd);
char				*ft_send_path(char *cmd);
char				**ft_create_args(char *args);

/*
** EXECUTION
*/

struct				s_get_binpath
{
	int				i;
	char			*ret;
	char			*tmp;
	char			*path_str;
	char			**paths;
};
struct				s_get_filtered_args
{
	int				i;
	char			*tmpstr;
	char			**ret;
	char			**tmp;
	char			**args;
};
void				ft_execute_handler(char *cmd, t_pipe *info);
void				ft_exit(char **args, char *cmd);
char				**filter_out_redirections(char *cmd);
int					ft_store_fd(int *stdin, int *stdout, int *stderr);
int					ft_restore_fd(int stdin, int stdout, int stderr);
char				*get_binpath(char *binname);
int					ft_execute(char **args, char *cmd, t_pipe *info);
int					builtin(char **args, char *cmd, t_pipe *info);

/*
** REDIRECTIONS
*/

char				*get_target(char *cmd, char *target);
char				*append_str(char *cmd);
int					redirection_handler(char *cmd, t_pipe *info);
int					is_redirect(char *cmd);
int					validate_redirect(char *cmd);
int					redirect_stdout(char *cmd, t_pipe *info);
int					redirect_stderr(char *cmd, t_pipe *info);
int					redirect_stdin(char *cmd, t_pipe *info);
int					openfile(char *filename, int is_append);
int					do_heredoc(char *close_str);
int					redirect_std_errin_fd(char *cmd, t_pipe *info);
int					redirect_std_to_std(char *cmd, t_pipe *info);
int					close_std(char *cmd, t_pipe *info);
int					is_close_std(char *cmd);
int					is_redirect_stdtostd(char *cmd);

/*
** COMMAND MANAGEMENT
*/

int					ft_is_opchar(int c);
void				ft_split_cmd(char *s);
char				*ft_normmilize_cmd(char *cmd);
void				copy_untill_char(char *cmd, char *new, t_iters *ij, char c);
void				basic_input(char *cmd, char *new, int i, int *j_ptr);
void				ft_resolve_redirection_args(char **args);
char				**ft_cmd_processor(char *cmd);
char				*ft_basic_input(char *cmd, int *i);
char				*ft_prefix_handler(char *cmd, int *i);
char				*ft_prefix_helper(char *cmd, int *i, int len, int end);
char				*ft_quote_handler(char *cmd, int *i);
int					contains_equalsign(char *arg);
void				ft_continue_if_is_var(int *i, int *k, char *cmd, char *new);

/*
** CD
*/

void				ft_cd(char **args);
char				*tidle_handler(char *dir);
char				*dash_handler(char *arg);
char				*dot_handler(char *dir);
char				*basic_handler(char *dir);
void				ft_path_builder(char *addr, char *root, char *filename);
char				*ft_path_builder2(char *root, char *filename);
void				ft_change_dir(char *dir);
char				*decrement_path(char *path);

/*
** ERROR HANDLING
*/

int					ft_validate(char **cmd);
void				ft_cmderror(char *message, char *arg);
void				ft_error(char *message);

/*
** PWD
*/

void				ft_pwd(void);

/*
** CANONICAL MODE
*/

typedef struct		s_screen
{
	size_t			width;
	size_t			height;
	size_t			min_y;
	size_t			min_x;
	size_t			y;
	size_t			mw_width;
	size_t			padding;
}					t_screen;

typedef struct		s_hist
{
	int				num;
	char			*name;
	struct s_hist	*next;
	struct s_hist	*prev;
}					t_history;

typedef struct		s_sfiles
{
	char			*filename;
	char			*folder;
}					t_sfiles;

typedef struct		s_tri
{
	struct s_tri	*letter[42];
	char			isword;
}					t_tri;

typedef struct		s_hash
{
	char			*name;
	struct s_hash	*next;
}					t_hash;

typedef struct		s_con
{
	char			*clipboard;
	struct s_screen	screen;
	struct s_hist	*history;
	struct s_tri	*trisearch;
	struct s_hash	*hashsearch[BINARY_MAX];
	char			*multiline;
	char			*morecommands;
	char			*temp;
	char			*tempstring;
	char			*shellcommands;
	char			closequote;
	char			closecommand;
	char			morelines;
	int				index;
	int				prompt_len;
	int				subshell;
}					t_con;

typedef struct		s_temp
{
	char			*suggest;
	int				n;
	t_con			*con;
	int				i;
}					t_temp;

int					manage_subshell(char **line, t_con *con, char *trimmed);
int					canonical_off(void);
int					canonical_on(void);
int					set_canonical(void);
void				k_action(int key, t_con *con);
void				add_history(char **line, t_con *con);
void				add_to_history(t_history **head, char *line);
char				*get_history(t_history **head, char dire);
int					get_key_line(char **line, t_con *con);
void				init_screen(t_con *con);
void				clear_line(char *str, t_con *con);
void				move_cursor(char dir, int *i, t_con *con);
int					move_word(int act, int *i, char *temp, t_con *con);
void				copy_selection(int act, int *i, char *temp, t_con *con);
void				del_left(char *temp, int *i, t_con *con);
void				del_right(char *temp, int *i, t_con *con);
void				home_key(int *i, t_con *con);
void				end_key(int *i, int str_len, t_con *con);
void				find_history(char dir, int *i, char *temp, t_con *con);
int					ft_puts(int c);
void				copy_to_clipboard(t_con *con, int *ind, char *temp);
void				paste_clipboard(t_con *con, int *i, char *temp);
void				get_y_pos(t_screen *screen, int x);
void				ctrlc_signal(char **str, t_con **con_set);
char				*new_cmd(char *cmd);
int					temp_failure(char **line, t_con *con);

/*
** AUTOCOMPLETE
*/

enum				{ADD, PRINT, RESET, NEXT, STORE};
void				init_autocomplete(t_con *con);
void				hash_word(char *name, t_con *env);
void				ctrld_signal(int *i, char *temp, t_con *con);
char				search(char **str, t_tri **head, t_con *con);
void				suggestions(char *word, char type, t_con *con, int *n);
void				show_usr_suggestions(char wrds[42][MAXWDIR], t_con *con);
void				show_suggestion(char *str, t_con *con);
char				check_line(t_con *con, char **line);
void				print_prompt(t_con *con);
void				remove_below(void);
int					is_binary(char *name, t_con *con);
char				get_tri_index(int ch);
int					search_files(char *trim, t_con *con);
void				init_prompt(t_con *con);
int					exit_prog(t_con *con);
DIR					*get_directory(t_sfiles *searchhelp, char *folder);
void				get_filename(t_sfiles *searchhelp, char *filename);
t_con				*ft_get_con(void);
void				find_suggestion(t_tri *mem[2000], t_tri **temp,
		int *len, t_temp *local);

/*
** HISTORY ACTION
*/

void				show_history(t_con *con);
char				action_history(char *trimmed, t_con *con, char **line);

/*
**	AND OR
*/
typedef struct		s_andor
{
    char			*comm;
    struct s_andor	*next;
}					t_andor;

void				free_2d_array(void **array);
t_andor				*chaining(char *str, int count);
char				**andor_management(char *str, char **env, int *val);
void				echo_vpipe(char *str, char **env, int *val);
char				*edit(char *str);
char				*size(char *segment, int *flag, int *i);
t_andor				*add_reset(t_andor *head, char *plc);
int					logical_op_count(char *str);
char				**run_logical(char *str, char **env, int *val);
t_andor				*new_andor(char *str);
t_andor				*add_andor(t_andor *head, char *str);
void				free_andor(t_andor *head);
void				print_andor(t_andor *head);
char				**command_list(t_andor *head, char **env);
t_andor				*first_node(char *str, int *flag, int *i);
t_andor				*new_reset(t_andor *head, int flag);
int					process2(char *first, char **env, int *status);
int					process_checker(char **env, char *str);
#endif
