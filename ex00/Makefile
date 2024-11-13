NAME= btc
CXXFLAGS=  -std=c++98 -Wall -Wextra -Werror -g3
CXX = c++

SRC = main.cpp BitcoinExchange.cpp

OBJ=$(SRC: .cpp=.o)

all= $(NAME)

%.o:%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(NAME):$(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re