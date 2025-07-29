# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lukitronix <lukitronix@student.42.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/14 12:33:14 by evgenkarlso       #+#    #+#              #
#    Updated: 2025/07/29 17:16:27 by lukitronix       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := bsq
SRC_DIR	= .
SRCS	= $(SRC_DIR)/main.c \
		  $(SRC_DIR)/ft_atoi.c \
		  $(SRC_DIR)/parser.c \
OBJS	= $(SRCS: .c=.o)
CC	= cc
CFLAGS	= -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re