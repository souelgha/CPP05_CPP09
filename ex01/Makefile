NAME= RPN
CXXFLAGS=  -std=c++98 -Wall -Wextra -Werror -g3
CXX = c++

SRC = main.cpp RPN.cpp

OBJ=$(SRC:.cpp=.o)

%.o:%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(NAME):$(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

all:$(NAME)

clean:
	rm -f $(OBJ)

fclean:clean
	rm -f $(NAME)

re:fclean all

.PHONY: all clean fclean re