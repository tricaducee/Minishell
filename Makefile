MAIND	= ./src/main
BUILD	= ./src/builtin
UTILD	= ./src/utils
PARSD	= ./src/parsing
PRINTD	= ./printfd
EXECD	= $(MAIND)/execution

MAINS	= main.c signaux.c
BUILS	= cmd_env.c cmd_cd.c cmd_echo.c cmd_exit.c cmd_pwd.c cmd_unset.c cmd_export.c
UTILS	= __init__.c ft_strlen.c ft_strdup.c ft_strjoin.c free_struct.c change_color.c ft_split.c handle_error.c ft_strcmp.c ft_get_env.c ft_get_export.c ft_get_shell.c \
		  ft_get_str_env.c ft_get_var.c ft_itoa.c ft_substr.c free_tab_null.c free_nodes.c ft_strinset.c ft_strncmp.c is_uppercase.c ft_atoi.c

PARSS	= add_andor.c add_cmd.c add_file.c add_quote.c cmdli_first.c create_cmdli.c free_cmdli.c get_cmds.c p_env.c print_tab.c type_and_set.c \
		  add_arg.c add_dquote.c add_pipe.c add_var.c cmdli_utils.c error_cmdli.c free_tab.c heredoc.c print_cmdli.c  split_cmd.c

PRINTS = counters/ft_strlen2.c main/flags_check_fd.c print_functions/print_len_fd.c print_functions/print_upx_fd.c	\
		text_mod/text_mod_fd.c utils/ft_putstr_fd.c counters/len_atoi.c main/ft_printfd.c print_functions/print_o_fd.c print_functions/print_x_fd.c \
		utils/ft_putchar_fd.c utils/ft_strchr.c counters/nbrlen.c print_functions/print_c_fd.c print_functions/print_s_fd.c text_mod/bright_fd.c \
		utils/ft_putnbr_fd.c counters/u_nbrlen_base.c print_functions/print_d_fd.c print_functions/print_u_fd.c text_mod/flags_text_fd.c \
		utils/ft_putnbrb_fd.c
EXECS	= exec_cmd.c get_absolute_path.c is_builtin.c set_redirection.c

NAME	= minishell

FLAGS	= -Wall -Wextra -Werror -I$(HOME)/.brew/opt/readline/include 

READLINE= -lreadline -L$(HOME)/.brew/opt/readline/lib 

ifeq ($(DEBUG), debug)
	FLAGS += -fsanitize=address -g3
endif
CC		= cc $(FLAGS)

MAINO	= $(addprefix $(MAIND)/,$(MAINS))
UTILO	= $(addprefix $(UTILD)/,$(UTILS))
BUILO	= $(addprefix $(BUILD)/,$(BUILS))
PARSO	= $(addprefix $(PARSD)/,$(PARSS))
PRINTO	= $(addprefix $(PRINTD)/,$(PRINTS))
EXECO	= $(addprefix $(EXECD)/, $(EXECS))

FILES	= $(MAINO) $(BUILO) $(UTILO) $(PARSO) $(PRINTO) $(EXECO)

OBJS	= $(FILES:.c=.o)

all: $(NAME)

$(NAME) : $(OBJS)
	@printf "\nCompiling executable \n"
	@$(CC) $(OBJS) -o $(NAME) $(READLINE) 
	@printf "Done\n"

%.o: %.c
	@printf "Compiling %-43.333s \r" $<
	@$(CC) -c $< -o $@

clean:
	@printf "Cleaning .o\n"
	@rm -f $(OBJS)

fclean: clean
	@printf "Cleaning executable\n"
	@rm -f $(NAME)


build:
	docker build -t arch .
	docker run -ti arch

prune:
	docker system prune -a --volumes

re: fclean all

.PHONY: re fclean clean all build prune
