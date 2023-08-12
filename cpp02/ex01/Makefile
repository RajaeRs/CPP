NAME = Fixed

HEADER = Fixed.hpp

SRC = main.cpp Fixed.cpp

OBJ = $(SRC:.cpp=.o)

CC = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

%.o: %.cpp
	$(CC) $(CXXFLAGS) -c $< -o $@

$(NAME) : $(OBJ) $(HEADER)
			$(CC) $(CXXFLAGS) $(SRC) -o $(NAME)

all: $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re : fclean all

.PHONY: all clean fclean re