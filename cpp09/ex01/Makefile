NAME =  RPN

HEADER =  RPN.hpp

SRC = main.cpp RPN.cpp

OBJ = $(SRC:.cpp=.o)

CC = c++

FLAGE = -Wall -Wextra -Werror -std=c++98

%.o: %.cpp
	$(CC) $(FLAGE) -c $< -o $@

$(NAME) : $(OBJ) $(HEADER)
			$(CC) $(FLAGE) $(SRC) -o $(NAME)

all: $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re : fclean all

.PHONY: all clean fclean re