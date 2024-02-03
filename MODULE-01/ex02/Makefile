# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pvilchez <pvilchez@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/03 23:33:34 by pvilchez          #+#    #+#              #
#    Updated: 2024/02/03 01:43:28 by pvilchez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ptrandref

CC = c++ -fsanitize=address
CFLAGS = -Wall -Wextra -Werror -std=c++98
REMOVE = rm -rf

SRC_FILE = main.cpp

HEADERS = -I ./

ORANGE = \033[1;38;5;208m
RESET = \033[0m
U_LINE = \033[4m
YELLOW = \033[1;38;5;226m

all: $(NAME)

$(NAME):
	@$(CC) $(CFLAGS) $(SRC_FILE) $(HEADERS) -o $(NAME)
	@echo "\n$(ORANGE)$(U_LINE)$(NAME): Mandatory Compiled$(RESET) \n"

clean:
	@echo "\n$(ORANGE)$(U_LINE)$(NAME): No object files to delete \n"

fclean: clean
	@$(REMOVE) $(NAME)

re: fclean all

.PHONY: all clean fclean re