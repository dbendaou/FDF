# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dbendaou <dbendaou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/05/10 16:16:05 by dbendaou          #+#    #+#              #
#    Updated: 2016/11/16 20:30:57 by dbendaou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		=	fdf

SRC_PATH	=	srcs
SRC_NAME	= 	main.c \
				parser.c \
				iso.c \
				mlx.c \
				check.c \
				draw.c \
				trace.c \
				get_next_line.c \
				
OBJ_NAME	=	$(SRC_NAME:.c=.o)
OBJ_PATH	=	objs

CPPFLAGS	= 	-Iinclude
CFLAGS 		=	-Wall -Wextra -Werror
LDFLAGS		=	-Llibft
LDLIBS		=	-lft
MLXFLAGS	=	-lmlx -framework OpenGL -framework AppKit

CC			=	clang

SRC			=	$(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ 		=	$(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

#COLORS
C_GOOD		=	"\033[32mSUCCESS\033[0m"
C_ORAN		=	"\033[33mCleaning "
C_RED		=	"\033[31mDelete   "
C_WHIT		= 	"\033[0m [ $(NAME) ]"
C_BLUE		=	"\033[34;1mCompiling"

all 	:	$(NAME)

$(NAME)	:	$(OBJ) libft/libft.a
		@$(CC) $(LDFLAGS) $(LDLIBS) $(MLXFLAGS) $^ -o $@
		@echo $(C_BLUE) $(C_WHIT) $(C_GOOD)

libft/libft.a :
		@make -C libft

objs/%.o: 	srcs/%.c
		@mkdir $(OBJ_PATH) 2> /dev/null || true
		@$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

clean :	
		@make clean -C libft
		@rm -f $(OBJ)
		@rmdir $(OBJ_PATH) 2> /dev/null || true
		@echo $(C_ORAN) $(C_WHIT) $(C_GOOD)

fclean :	 clean
		@make fclean -C libft
		@rm -rf $(NAME)
		@echo $(C_RED) $(C_WHIT) $(C_GOOD)

re :		fclean all

.PHONY: 	all, clean, fclean, re