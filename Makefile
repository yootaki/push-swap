
PUSH_SWAP = push_swap
CHECKER = checker

CC = gcc
CFLAGS = -Wall -Wextra -Werror

LIBS = includes/libft/libft.a includes/mylibft/mylibft.a

PS_SRCS = srcs/pushswap.c\
srcs/small_sort.c\
srcs/radix_sort.c

CH_SRCS = bonus/checker.c\
includes/get_next_line/get_next_line.c\
includes/get_next_line/get_next_line_utils.c

SRCS = srcs/args_check.c\
srcs/commands_a.c\
srcs/commands_b.c\
srcs/commands.c\
srcs/lst_func.c\
srcs/utils.c

PS_BOJS = $(PS_SRCS:.c=.o) $(SRCS:.c=.o)
CH_BOJS = $(CH_SRCS:.c=.o) $(SRCS:.c=.o)

DEBUG_DIR = push_swap.dSYM

# **************************************************
# **************************************************

all: $(PUSH_SWAP)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

$(PUSH_SWAP): $(PS_BOJS) $(LIBS)
	$(CC) $(CFLAGS) -o push_swap $(PS_BOJS) $(LIBS)

$(CHECKER): $(CH_BOJS) $(LIBS)
	$(CC) $(CFLAGS) -o checker $(CH_BOJS) $(LIBS)

$(LIBS):
	$(MAKE) -C includes/libft/
	$(MAKE) -C includes/mylibft/

bonus: all $(CHECKER)

# **************************************************
# **************************************************

clean:
	rm -rf $(DEBUG_DIR) $(PS_BOJS) $(CH_BOJS)
	$(MAKE) fclean -C includes/libft/
	$(MAKE) fclean -C includes/mylibft/

fclean: clean
	rm -f $(PUSH_SWAP)
	rm -f $(CHECKER)

re: fclean all

# **************************************************
# **************************************************

#セグフォなどのデバッグ用フラグ
debug: CFLAGS += -g3 -fsanitize=address

debug: re

# **************************************************
# **************************************************

.PHONY: all bonus debug fclean clean re
