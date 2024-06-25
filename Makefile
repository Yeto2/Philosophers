# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yessemna <yessemna@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/30 18:09:58 by yessemna          #+#    #+#              #
#    Updated: 2024/06/25 04:41:51 by yessemna         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = philo.c \
		utils/ft_atoi.c \
		utils/parssing.c \
		utils/init.c \
		utils/time.c \
		utils/actions.c \
		utils/routine.c \
		utils/free.c \
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