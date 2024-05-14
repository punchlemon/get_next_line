# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: retanaka <retanaka@student.42.tokyo>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/14 16:38:27 by retanaka          #+#    #+#              #
#    Updated: 2024/05/14 16:47:52 by retanaka         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				=	test
CC					=	cc
CFLAGS				=	-Wall -Wextra -Werror
INCLUDE				=	include

all:
					@$(CC) $(CFLAGS) -I$(INCLUDE) -c src/main.c -o src/main.o
					@$(CC) $(CFLAGS) src/main.o -o $(NAME)