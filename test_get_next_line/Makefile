# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: retanaka <retanaka@student.42.tokyo>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/14 16:38:27 by retanaka          #+#    #+#              #
#    Updated: 2024/05/15 20:09:27 by retanaka         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	test
INCLUDE		=	include
GNL_DIR		=	../
SRC_DIR		=	src/
OBJ_DIR		=	obj/
SRC_EXT		=	.c
OBJ_EXT		=	.o
CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror
IFLAGS		=	-I$(INCLUDE) -I$(GNL_DIR)
RM			=	rm -f
AR			=	ar rcs
ifdef BUFFER_SIZE
CFLAGS		+=	-DBUFFER_SIZE=$(BUFFER_SIZE)
endif

# Colors
DEF_COLOR	=	\033[0;39m
GRAY		=	\033[0;90m
RED			=	\033[0;91m
GREEN		=	\033[0;92m
YELLOW		=	\033[0;93m
BLUE		=	\033[0;94m
MAGENTA		=	\033[0;95m
CYAN		=	\033[0;96m
WHITE		=	\033[0;97m

SRC_FILES	=	$(notdir $(basename $(wildcard $(SRC_DIR)*$(SRC_EXT))))
SRC_FILES	+=	$(notdir $(basename $(wildcard $(GNL_DIR)*$(SRC_EXT))))
SRC			=	$(addprefix $(SRC_DIR), $(addsuffix $(SRC_EXT), $(SRC_FILES)))
OBJ			=	$(addprefix $(OBJ_DIR), $(addsuffix $(OBJ_EXT), $(SRC_FILES)))
OBJF		=	.cache_exists

all:		$(NAME)

$(NAME):	$(OBJ)
			@$(CC) $(CFLAGS) $(IFLAGS) $(OBJ) -o $(NAME)
			@echo "$(GREEN)test compiled!$(DEF_COLOR)"
			@./$(NAME)

$(OBJ_DIR)%$(OBJ_EXT): $(GNL_DIR)%$(SRC_EXT) | $(OBJF)
			@echo "$(YELLOW)Compiling: $< $(DEF_COLOR)"
			@$(CC) $(CFLAGS) -I$(GNL_DIR) -c $< -o $@

$(OBJ_DIR)%$(OBJ_EXT): $(SRC_DIR)%$(SRC_EXT) | $(OBJF)
			@echo "$(YELLOW)Compiling: $< $(DEF_COLOR)"
			@$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

$(OBJF):
			@mkdir -p $(OBJ_DIR)

clean:
			@$(RM) -r $(OBJ_DIR)
			@echo "$(BLUE)Object files cleaned!$(DEF_COLOR)"

fclean:		clean
			@$(RM) $(NAME)
			@echo "$(CYAN)Executable files cleaned!$(DEF_COLOR)"

re:			fclean all
#			@echo "$(CYAN)Cleaned and rebuilt everything for test!$(DEF_COLOR)"

norm:
			@norminette $(SRC) $(INCLUDE) | grep -v Norme -B1 || true

.PHONY:		all clean fclean re norm