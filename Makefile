
NAME = push_swap
DEBUG_DIR = push_swap.dSYM

CC = gcc
CFLAGS = -Wall -Wextra -Werror

LIBS = libft/libft.a mylibft/mylibft.a

SRCS = pushswap_v2.c

OBJS = $(SRCS:.c=.o)

# **************************************************
# **************************************************

all: $(LIBS)
	$(CC) $(CFLAGS) -o push_swap $(SRCS) $(LIBS)

$(LIBS):
	$(MAKE) -C libft/
	$(MAKE) -C mylibft/

# **************************************************
# **************************************************

bonus: all

clean:
	rm -f $(OBJS)
	rm -rf $(DEBUG_DIR)
	$(MAKE) fclean -C libft/
	$(MAKE) fclean -C mylibft/

fclean: clean
	rm -f $(NAME)

re: fclean all

# **************************************************
# **************************************************

#セグフォなどのデバッグ用フラグ
debug: CFLAGS += -g3 -fsanitize=address

debug: re

# **************************************************
# **************************************************

.PHONY: all bonus debug fclean clean re
