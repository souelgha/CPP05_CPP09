NAME= serializer
CXXFLAGS= -std=c++98 -Wall -Wextra -Werror -g3
CXX=c++

SRC= Serializer.cpp main.cpp

OBJ=$(SRC:.cpp=.o)

%.o:%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

all:$(NAME)

$(NAME):$(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)
fclean:clean
	rm -f $(NAME)

re : fclean all

.PHONY: re clean fclean all