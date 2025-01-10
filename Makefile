# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arosa-di <arosa-di@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/05 19:18:05 by arosa-di          #+#    #+#              #
#    Updated: 2025/01/07 21:53:37 by arosa-di         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =	src/pipex.c \
		src/utils.c \

OBJS_SRC = $(SRC:.c=.o)

CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -g

NAME = pipex
LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a

all: $(NAME)

$(NAME): $(OBJS_SRC) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS_SRC) $(LIBFT) -o $(NAME)

$(LIBFT): $(LIBFT_OBJS)
	$(MAKE) -C $(LIBFT_PATH) all

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS_SRC)
	$(MAKE) -C $(LIBFT_PATH) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_PATH) fclean

re: fclean all

.PHONY: all clean fclean re