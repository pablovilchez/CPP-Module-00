# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pvilchez <pvilchez@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/03 23:33:34 by pvilchez          #+#    #+#              #
#    Updated: 2024/02/06 09:02:01 by pvilchez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = zombiehorde

CC = c++ #-fsanitize=address
CFLAGS = -Wall -Wextra -Werror -std=c++98
REMOVE = rm -rf

OBJ_PATH = obj

HEADERS = -I ./

SRC_FILES = main.cpp Zombie.cpp zombieHorde.cpp

SRC := $(SRC_FILES)
OBJ = $(SRC:%.cpp=$(OBJ_PATH)/%.o)

ORANGE = \033[1;38;5;208m
RESET = \033[0m
U_LINE = \033[4m
YELLOW = \033[1;38;5;226m

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(FLAGS) $(OBJ) $(HEADERS) -o $@
	@echo "\n$(ORANGE)$(U_LINE)$(NAME): Mandatory Compiled$(RESET) \n"

$(OBJ_PATH)/%.o: %.cpp
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(FLAGS) -o $@ -c $< $(HEADERS)
	@echo "$(YELLOW)$(NAME) Compiling:$(RESET) $(notdir $<)"

clean:
	@$(REMOVE) $(OBJ_PATH)

fclean: clean
	@$(REMOVE) $(NAME)

re: fclean all

.PHONY: all clean fclean re