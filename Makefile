MAIND	= ./src/main
BUILD	= ./src/builtin
UTILD	= ./src/utils

MAINS	= main.c signaux.c
BUILS	= builtin.c
UTILS	= __init__.c ft_strlen.c ft_strdup.c ft_strjoin.c free_struct.c change_color.c ft_split.c handle_error.c

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

FILES	= $(MAINO) $(BUILO) $(UTILO)

OBJS	= $(FILES:.c=.o)

all: $(NAME)

$(NAME) : $(OBJS)
	@printf "\nCompiling executable \n"
	@$(CC) $(OBJS) -o $(NAME) $(READLINE) 
	@printf "Done\n"

%.o: %.c
	@printf "Compiling %-33.333s \r" $<
	@$(CC) -c $< -o $@

clean:
	@printf "Cleaning .o\n"
	@rm -f $(OBJS)

fclean: clean
	@printf "Cleaning executable\n"
	@rm -f $(NAME)

re: fclean all

build:
	docker build -t arch .
	docker run -ti arch
prune:
	docker system prune -a --volumes

.PHONY: re fclean clean all build prune
