NAME = AMateria

HEADER = AMateria.hpp Ice.hpp Cure.hpp ICharacter.hpp Character.hpp IMateriaSource.hpp MateriaSource.hpp

SRC = main.cpp AMateria.cpp Ice.cpp Cure.cpp Character.cpp MateriaSource.cpp SaveAddress.cpp

OBJ = $(SRC:.cpp=.o)

CC = c++

CXXFLAGES = -Wall -Wextra -Werror -std=c++98

%.o: %.cpp
	$(CC) $(CXXFLAGES) -c $< -o $@


$(NAME) : $(OBJ) $(HEADER)
			$(CC) $(CXXFLAGES) $(SRC) -o $(NAME)

all: $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re : fclean all

.PHONY: all clean fclean re