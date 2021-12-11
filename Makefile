# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pnielly <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/10 20:59:10 by pnielly           #+#    #+#              #
#    Updated: 2021/12/11 13:28:50 by pnielly          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#----- Executables
NAME=hotrace

#----- Commands
CC=cc
FLAGS=-Wall -Wextra -Werror

#----- SRCS
SRCS=hotrace.c

#----- OBJS
OBJS=$(SRCS:.c=.o)

#Colors
BLACK:="\033[1;30m"
RED:="\033[1;31m"
GREEN:="\033[1;32m"
PURPLE:="\033[1;35m"
CYAN:="\033[1;36m"
WHITE:="\033[1;37m"
EOC:="\033[0;0m"

# ---------- Rules
all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(FLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	@$(CC) $(FLAGS) -o $@ -c $<

clean:
	@rm -rf $(OBJS) 

fclean: clean
	@rm -rf $(NAME)
	
re: fclean all

.PHONY: all clean fclean re
