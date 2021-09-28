# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/09 21:09:38 by jvaquer           #+#    #+#              #
#    Updated: 2021/09/20 18:22:08 by jvaquer          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = tester_vector

SRC = 	./tester/tester_vector.cpp	

OBJ = $(SRC:.cpp=.o)

CXX = clang++

CPPFLAGS = -Wall -Werror -Wextra -std=c++98

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
