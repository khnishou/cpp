
NAME = ex02

FLAGS = -Wall -Werror -Wextra -std=c++98

SRC = Bureaucrat.cpp main.cpp AForm.cpp

OBJ = $(SRC:.cpp=.o)

$(NAME): $(OBJ)
	@c++ $(OBJ) $(FLAGS) -o $(NAME)

all: $(NAME)

clean: 
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

run: re
	./$(NAME)