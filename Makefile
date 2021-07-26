
PUSH_SWAP = push_swap
CHECKER = checker

CC = gcc
CFLAGS = -Wall -Wextra -Werror

LIBS = includes/libft/libft.a includes/mylibft/mylibft.a

PS_SRCS = srcs/pushswap.c\

CH_SRCS = srcs/checker.c\
includes/get_next_line/get_next_line.c\
includes/get_next_line/get_next_line_utils.c

SRCS = srcs/commands_a.c\
srcs/commands_b.c\
srcs/commands.c\
srcs/lst_func.c\
srcs/utils.c

DEBUG_DIR = push_swap.dSYM

# **************************************************
# **************************************************

all: $(LIBS)
	$(CC) $(CFLAGS) -o push_swap $(PS_SRCS) $(SRCS) $(LIBS)
	$(CC) $(CFLAGS) -o checker $(CH_SRCS) $(SRCS) $(LIBS)

$(LIBS):
	$(MAKE) -C includes/libft/
	$(MAKE) -C includes/mylibft/

bonus: all

# **************************************************
# **************************************************

clean:
	rm -rf $(DEBUG_DIR)
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
