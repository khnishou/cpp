# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ykerdel <ykerdel@student.42heilbronn.de    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/08 04:46:32 by ykerdel           #+#    #+#              #
#    Updated: 2023/08/10 05:17:26 by ykerdel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Harl_2.0

FLAGS = -Wall -Werror -Wextra -std=c++98

SRC = Harl.cpp	main.cpp

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