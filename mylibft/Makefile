# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yootaki <yootaki@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/12 10:35:58 by yootaki           #+#    #+#              #
#    Updated: 2021/04/19 15:18:26 by yootaki          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = mylibft.a
CFLAGS = -Wall -Wextra -Werror
CC = gcc
HEADER = mylibft.h
SRCS = ft_issmall.c\
ft_islarge.c\
ft_atof.c

OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

all: $(NAME)

.c.o: $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	ar rsc $(NAME) $(OBJS)

bonus: $(NAME) $(BONUS_OBJS)
	ar rsc $(NAME) $(BONUS_OBJS)

clean:
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
