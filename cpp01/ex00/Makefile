SRC = main.cpp  Zombie.cpp newZombie.cpp randomChump.cpp

NAME = zombie

HEADER = Zombie.hpp 

OBJ = $(SRC:.cpp=.o)

CC = c++

FLAGE = -Wall -Wextra -Werror  -std=c++98

all : $(NAME)

$(NAME) : $(OBJ) $(HEADER)
		$(CC) $(FLAGE) $(OBJ) -o $(NAME) 

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY: all clean fclean re