# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/01 11:50:26 by jvaquer           #+#    #+#              #
#    Updated: 2021/10/05 15:52:22 by jvaquer          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = tester_stack

SRC = 	./tester/tester_stack.cpp	

OBJ = $(SRC:.cpp=.o)

CC = clang++

CPPFLAGS = -Wall -Wextra -Werror -std=c++98

all : $(NAME)

$(NAME) :	$(OBJ)
			$(CC) $(CPPFLAGS) -o $(NAME) $(OBJ)

clean :
			rm -rf $(OBJ)

fclean : clean
			rm -rf $(NAME)

re : fclean all