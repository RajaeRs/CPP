NAME =  BureaucratForm

HEADER = Bureaucrat.hpp AForm.hpp ShrubberyCreationForm.hpp

SRC = main.cpp Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp

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