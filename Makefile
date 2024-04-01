# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yessemna <yessemna@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/30 18:09:58 by yessemna          #+#    #+#              #
#    Updated: 2024/04/01 00:07:24 by yessemna         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = philo.c \
		utils/error.c \
		utils/parssing.c \
		utils/init.c \
		utils/handle_err.c \
		utils/ft_putstr_fd.c \

OBJ = $(SRC:.c=.o)

all: $(NAME)

%.o: %.c philo.h
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)


clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re