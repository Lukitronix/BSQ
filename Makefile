# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lukitronix <lukitronix@student.42.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/14 12:33:14 by evgenkarlso       #+#    #+#              #
#    Updated: 2025/07/28 22:21:24 by lukitronix       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := bsq
CC := cc
FLAGS := -Wall -Werror -Wextra
SRC_DIR := .
OBJ_DIR := ./obj/
SRC_FILES := $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES := $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)%.o,$(SRC_FILES))
RM := rm -rf

all: obj $(NAME)

obj:
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)/%.c
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJ_FILES)
	$(CC) $(FLAGS) -o $@ $^

clean:
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re obj