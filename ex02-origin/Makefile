# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sonouelg <sonouelg@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/21 10:22:59 by sonouelg          #+#    #+#              #
#    Updated: 2024/11/21 15:29:46 by sonouelg         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = PmergeMe

CXXFLAGS = -std=c++98 -Wall -Wextra -Werror -g3
CXX = c++

SRC= main.cpp PmergeMe.cpp

OBJ=$(SRC:.cpp=.o)

all:$(NAME)

%.o:%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(NAME):$(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)
fclean:clean 
	rm -f $(NAME)

re : fclean all

.PHONY: re all clean fclean

