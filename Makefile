#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acoulomb <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/03 22:08:39 by acoulomb          #+#    #+#              #
#    Updated: 2018/04/23 17:51:24 by acoulomb         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

.PHONY = re all clean fclean
.SUFFIXES:

NAME = fillit

SRC =	main.c \
		tetrimino.c \
		tetrimino.h \
		tetrimino_pattern.c \
		tetrimino_pattern.h \
		tetriminos \
		tetris_board.h

OBJS = $(SRC:.c=.o)

LIB = ./libft/libft.a

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	@gcc $(FLAGS) -o $(NAME) $(OBJS) $(LIB)

%.o : %.c
	gcc $(FLAGS) -c $^

clean:
	@/bin/rm -f $(OBJS)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all

g: fclean $(OBJS)
	gcc $(FLAGS) -g $(NAME) $(OBJS) $(LIB)