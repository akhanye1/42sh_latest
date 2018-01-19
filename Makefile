# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkgosise <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/11 17:46:12 by mkgosise          #+#    #+#              #
#    Updated: 2018/01/19 14:04:05 by angonyam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 42sh

OBJ_DIR = ./obj

AUTO_C = hash.c search.c searchdir.c suggestion_help.c init_autocomplete.c\
		 searchaction.c searchfiles.c suggestions.c
DIR1 = $(addprefix autocomplete/, $(AUTO_C))
CMD_M = ft_basic_input_handler.c ft_normilize_cmd.c ft_split_args.c\
		ft_cmd_processor.c ft_resolve_redirection_args.c ft_split_cmd.c 
DIR2 = $(addprefix cmd_management/, $(CMD_M))
ERRORS = ft_errors.c
DIR3 = $(addprefix error_handling/, $(ERRORS))
HISTORY = ft_history.c history_action.c show_history.c
DIR4 = $(addprefix history/, $(HISTORY))
DIR5 = main.c free.c error.c
SIGNALS = ft_handle_all.c
DIR6 = $(addprefix signals/, $(SIGNALS))
BACKTICKS = backticks_handler.c backticks_helper.c
DIR7 = $(addprefix backticks/, $(BACKTICKS))
ECHO = echo_handler.c
DIR8 = $(addprefix echo/, $(ECHO))
EXEC = builtin.c filter_out_redirections.c ft_execute_helper.c exit.c\
	   ft_execute.c
DIR9 = $(addprefix execute/, $(EXEC))
LINE_M = canonical.c ctrlc_signal.c delkey.c ft_puts.c quotes.c\
		 clipboard.c ctrld_signal.c ft_keyaction.c init_propmt.c screen.c copy.c\
		 cursor.c	ft_keytrigger.c prompt.c words.c subshell.c edit_subshell.c\
		 multiline.c
DIR10 = $(addprefix line_management/, $(LINE_M))
PIPES = ft_handle_pipes.c ft_pipe_helper.c ft_pipe_recursive.c\
	  ft_save_to_file.c ft_initialize_pipes.c ft_pipe_helper_func.c\
	  ft_pipe_red.c
DIR11 = $(addprefix pipe_functions/, $(PIPES))
VALIDATE = ft_validate.c
DIR12 = $(addprefix validation/, $(VALIDATE))
CD = ft_cd.c ft_cd_handlers.c
DIR13 = $(addprefix cd/, $(CD))
ENVIRON = ft_env.c ft_env_helper.c
DIR14 = $(addprefix environment/, $(ENVIRON))
LOCAL_VAR = ft_export.c ft_get_local_variables.c ft_local_helpers.c
DIR15 = $(addprefix local_variables/, $(LOCAL_VAR))
REDIRECTS = close_std.c redirect_helper.c redirect_stderr.c\
			redirections_handler.c get_target.c redirect_std_errin_fd.c\
			redirect_stdin.c validate_redirect.c heredoc.c redirect_std_to_std.c\
			redirect_stdout.c
DIR16 = $(addprefix redirections/, $(REDIRECTS))
ANDOR = logical_process.c setup.c echo3.c setup2.c andor.c free_2d_array.c logical_builtins.c\
		process_check.c start.c
DIR17 = $(addprefix andor/, $(ANDOR))
SRC = $(addprefix src/, $(DIR1) $(DIR2) $(DIR3) $(DIR4) $(DIR5) $(DIR6) $(DIR7)\
$(DIR8) $(DIR9) $(DIR10) $(DIR11) $(DIR12) $(DIR13) $(DIR14) $(DIR15) $(DIR16)\
$(DIR17))
OBJ = $(CMD_M:%.c=%.o) $(ERRORS:%.c=%.o) $(AUTO_C:%.c=%.o) $(HISTORY:%.c=%.o)\
	$(DIR5:%.c=%.o) $(SIGNALS:%.c=%.o) $(BACKTICKS:%.c=%.o) $(ECHO:%.c=%.o)\
	$(EXEC:%.c=%.o) $(LINE_M:%.c=%.o) $(PIPES:%.c=%.o) $(VALIDATE:%.c=%.o)\
	$(CD:%.c=%.o) $(ENVIRON:%.c=%.o) $(LOCAL_VAR:%.c=%.o) $(REDIRECTS:%.c=%.o)\
	$(ANDOR:%.c=%.o)

OBJ_D = $(addprefix $(OBJ_DIR)/, $(OBJ))

FLAGS = -Wall -Wextra -Werror

LIBFT = ./libft/
LIBTERMCAP = -ltermcap

all: $(OBJ_DIR) $(LIBFT) $(NAME)

$(OBJ_DIR): $(SRC)
	@echo "\033[0;33mCompiling 42sh...\033[0m"
	@mkdir -p $(OBJ_DIR)
	@clang -c $(FLAGS) $(SRC) -g
	@mv $(OBJ) $(OBJ_DIR)
	@echo "\033[0;33mObject files moved to '$(OBJ_DIR)'\033[0m"

$(NAME): $(OBJ_D)
	@make -C $(LIBFT)
	@echo "\033[0;32mLIBFT Compiled\033[0m"
	@clang -o $(NAME) $(FLAGS) $(OBJ_D) -L$(LIBFT) -lft $(LIBTERMCAP)
	@echo "\033[0;32m42sh Compiled\033[0m"

clean:
	@rm -rf $(OBJ_DIR)
	@rm -f $(OBJ)
	@make -C libft/ clean
	@echo "\033[0;36mObject files removed!\033[0m"

fclean: clean
	@rm -f $(NAME)
	@make -C libft/ fclean
	@echo "\033[0;36mExecutable removed!\033[0m"

re: fclean all
