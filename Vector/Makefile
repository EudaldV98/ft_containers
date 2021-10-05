# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/09 21:09:38 by jvaquer           #+#    #+#              #
#    Updated: 2021/10/05 15:54:15 by jvaquer          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = tester_vector

NAME_MAIN = main_vector

SRC = 	./tester/tester_vector.cpp	

SRCS =	./tester/main.cpp

OBJ = $(SRC:.cpp=.o)

OBJS = $(SRCS:.cpp=.o)

CXX = clang++

CPPFLAGS = -Wall -Werror -Wextra -std=c++98

all : test_map main_map

test_map :	$(OBJ)
			$(CXX) $(CPPFLAGS) -o $(NAME) $(OBJ)

main_map :	$(OBJS)
			$(CXX) $(CPPFLAGS) -o $(NAME_MAIN) $(OBJS)

clean :
			rm -rf $(OBJ)
			rm -rf $(OBJS)

fclean : clean
			rm -rf $(NAME)
			rm -rf $(NAME_MAIN)

re : fclean all
