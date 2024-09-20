# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yessemna <yessemna@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/30 18:09:58 by yessemna          #+#    #+#              #
#    Updated: 2024/09/14 00:00:15 by yessemna         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = philo.c					\
		utils/ft_atoi.c			\
		utils/parssing.c		\
		utils/init.c			\
		utils/time.c			\
		utils/actions.c			\
		utils/routine.c			\
		utils/free.c			\
		utils/ft_putstr_fd.c	\
		utils/ft_malloc.c		\
		utils/ft_malloc_tools.c \

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