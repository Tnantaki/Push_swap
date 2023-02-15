NAME = push_swap

CC = gcc

FLAGS = -Wall -Wextra -Werror

RM = rm -f

LIBFT_PATH = libft/
ACTIONS_PATH = actions/

SWAP_SRCS = 1_push_swap.c 2_check_arg.c 3_lst_num.c 4_sorting.c 5_utils.c ft_showstack.c quick_sort.c

LIBFT_SRCS = ft_atoi.c ft_isdigit.c ft_strlen.c ft_split.c\
			ft_lstnew.c ft_lstadd_front.c ft_lstadd_back.c\
			ft_lstlast.c ft_lstbefore_last.c ft_delcont.c\
			ft_lstdelone.c ft_lstclear.c ft_lstsize.c

ACTIONS_SRCS = ft_swap.c ft_rotate.c ft_reverse_rotate.c ft_push.c

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
