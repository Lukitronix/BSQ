# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lukitronix <lukitronix@student.42.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/14 12:33:14 by evgenkarlso       #+#    #+#              #
#    Updated: 2025/07/28 21:24:02 by lukitronix       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := bsq
CC := cc
FLAGS := -Wall -Werror -Wextra
SRC_DIR := .
OBJ_DIR	:= ./obj/
SRC_FILES := $(wildcard $(SRC_DIR)/*.c)

OBJ_FILES = $(notdir $(SRC_FILES:.c=.o))
SRCS = $(SRC_FILES)
OBJS = $(addprefix $(OBJ_DIR), $(OBJ_FILES))
HEADER := -I includes/
RM := rm -rf

all: obj $(NAME)

obj: $(SRCS)
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(CC) $(FLAGS) -c $< -o $@ $(HEADER)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) -o $(NAME) $(OBJS) $(HEADER)

clean:
	$(RM) $(OBJ_DIR)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re