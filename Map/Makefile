# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/03 14:12:12 by jereligi          #+#    #+#              #
#    Updated: 2021/10/05 15:33:20 by jvaquer          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = tester_map

NAME_MAIN = main_map 

SRC = 	./tester/tester_map.cpp

SRC_MAIN = ./tester/main_map.cpp

OBJ = $(SRC:.cpp=.o)

OBJ_MAIN = $(SRC_MAIN:.cpp=.o)

CC = clang++

CPPFLAGS = -Wall -Wextra -Werror -std=c++98

all : test_map main_map

test_map :	$(OBJ)
			$(CC) $(CPPFLAGS) -o $(NAME) $(OBJ)

main_map :	$(OBJ_MAIN)
			$(CC) $(CPPFLAGS) -o $(NAME_MAIN) $(OBJ_MAIN)

clean :
			rm -rf $(OBJ)
			rm -rf $(OBJ_MAIN)

fclean : clean
			rm -rf $(NAME)
			rm -rf $(NAME_MAIN)

re : fclean all