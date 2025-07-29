# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lukitronix <lukitronix@student.42.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/14 12:33:14 by evgenkarlso       #+#    #+#              #
#    Updated: 2025/07/29 17:39:04 by lukitronix       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := bsq
CC := cc
FLAGS := -Wall -Werror -Wextra
SRC_DIR := ./src
OBJ_DIR := ./obj
SRC_FILES := main.c \
             parser.c \
             ft_atoi.c
OBJ_FILES := $(SRC_FILES:.c=.o)
SRCS := $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJS := $(addprefix $(OBJ_DIR)/, $(OBJ_FILES))
HEADER := -I includes/
RM := rm -f

all: $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(FLAGS) -c $< -o $@ $(HEADER)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) -o $@ $(OBJS) $(HEADER)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re