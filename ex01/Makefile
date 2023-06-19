SRC = main.cpp  addContact.cpp geters.cpp seters.cpp search.cpp

NAME = phonebook

OBJ = $(SRC:.c=.o)

CC = c++

FLAGE = -Wall -Wextra -Werror  -std=c++98

all : $(NAME)

%.o: %.c 
	$(CC) -c $< -o $@

$(NAME) : $(OBJ) 
		$(CC) $(FLAGE) $(SRC) -o $(NAME)

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean $(NAME)

.PHONY: all clean fclean re