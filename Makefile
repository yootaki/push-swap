
NAME = push_swap
BONUS = checker

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCS = srcs/pushswap.c\
srcs/small_sort.c\
srcs/radix_sort.c\
srcs/args_check.c\
srcs/commands_a.c\
srcs/commands_b.c\
srcs/commands.c\
srcs/lst_func.c\
srcs/utils.c

BONUS_SRCS = bonus/checker.c

UTILS = utils/libft/libft.a\
utils/mylibft/mylibft.a\
utils/get_next_line/get_next_line.c\
utils/get_next_line/get_next_line_utils.c

OBJS = $(SRCS:.c=.o) $(UTILS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o) $(UTILS:.c=.o)

DEBUG_DIR = push_swap.dSYM

# **************************************************
# **************************************************

all: $(NAME)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS) $(UTILS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

$(BONUS): $(BONUS_OBJS) $(UTILS)
	$(CC) $(CFLAGS) -o $(BONUS) $(BONUS_OBJS)

$(UTILS):
	$(MAKE) -C utils/libft/
	$(MAKE) -C utils/mylibft/

bonus: all $(BONUS)

# **************************************************
# **************************************************

clean:
	$(RM) $(DEBUG_DIR) $(OBJS) $(BONUS_OBJS)
	$(MAKE) fclean -C utils/libft/
	$(MAKE) fclean -C utils/mylibft/

fclean: clean
	rm -f $(NAME)
	rm -f $(BONUS)

re: fclean all

# **************************************************
# **************************************************

debug: CFLAGS += -g3 -fsanitize=address

debug: re

# **************************************************
# **************************************************

.PHONY: all bonus debug fclean clean re
