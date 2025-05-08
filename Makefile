# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kkurowsk <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/08 15:04:08 by kkurowsk          #+#    #+#              #
#    Updated: 2025/05/08 15:04:11 by kkurowsk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk

CC = cc
CFLAGS = -Wall -Wextra -Werror -g

SRCS = server.c client.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@make clean -C
	rm -f $(OBJS)

fclean: clean
	@make fclean -C
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
