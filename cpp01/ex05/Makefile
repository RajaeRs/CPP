NAME = harl

HEADER = Harl.hpp

SRC = main.cpp Harl.cpp

OBJ = $(SRC:.cpp=.o)

CC = c++

FLAGE = -Wall -Wextra -Werror -std=c++98

$(NAME) : $(OBJ) $(HEADER)
		$(CC) $(FLAGE) $(SRC) -o $(NAME)

all: $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re