NAME = push_swap

CC = gcc

FLAGS = -Wall -Wextra -Werror

RM = rm -f

LIBFT_PATH = libft/
ACTIONS_PATH = actions/

SWAP_SRCS = pushswap.c ft_check_err.c ft_case_3.c ft_showstack.c

LIBFT_SRCS = ft_atoi.c ft_isdigit.c ft_strlen.c ft_putstr_fd.c ft_putendl_fd.c\
			ft_split.c ft_lstnew.c ft_lstadd_front.c ft_lstadd_back.c\
			ft_lstlast.c ft_lstbefore_last.c ft_delcont.c ft_lstdelone.c\
			ft_lstclear.c ft_lstsize.c

ACTIONS_SRCS = ft_pop2top.c ft_swap_2top.c ft_swap_bot2top.c ft_swap_top2bot.c

SRCS = $(SWAP_SRCS)\
	   $(addprefix $(ACTIONS_PATH), $(ACTIONS_SRCS))\
	   $(addprefix $(LIBFT_PATH), $(LIBFT_SRCS))

OBJS = $(SRCS:.c=.o)

all: $(NAME)

%.o:%.c
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re