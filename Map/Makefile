# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/03 14:12:12 by jereligi          #+#    #+#              #
#    Updated: 2021/09/23 14:48:21 by jvaquer          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = tester_map

SRC = 	./tester.cpp	

OBJ = $(SRC:.cpp=.o)

CC = clang++

CPPFLAGS = -Wall -Wextra -Werror -std=c++98

all : $(NAME)

$(NAME) :	$(OBJ)
			$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

sanitize : 	$(OBJ)
			$(CC) -o $(NAME) -fsanitize=address $(CPPFLAGS) $(OBJ)

clean :
			rm -rf $(OBJ)

fclean : clean
			rm -rf $(NAME)

re : fclean all