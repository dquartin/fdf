# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dquartin <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/06 17:31:58 by dquartin          #+#    #+#              #
#    Updated: 2018/04/18 21:28:44 by dquartin         ###   ########.fr        #
#    Updated: 2018/02/05 17:56:51 by dquartin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
CC = gcc
OPTIONS = -c
FLAGS = -Wall -Wextra -Werror
MLXFLAGS = -lmlx -framework OpenGL -framework Appkit
SRCS = main.c\
	   init_fdf.c\
	   draw_line.c
LIB = -C ./libft/
OBJS = $(SRCS:.c=.o)
RM = rm -rf

MAKEFLAGS = s

Y = "\033[33m"
R = "\033[31m"
G = "\033[32m"
B = "\033[34m"
X = "\033[0m"
UP = "\033[A"
CUT = "\033[K"

all : $(NAME)

%.o: %.c
	@echo ${Y}Compiling [$@]...${X}
	@$(CC) $(FLAGS) -I ./libft -o $@ -c $<
	@printf ${UP}${CUT}

$(NAME) : $(OBJS)
	@make $(LIB)
	@$(CC) $(FLAGS) $(MLXFLAGS) -o $(NAME) $(OBJS) -L ./libft -lft
	@echo "\033[01;32mCompilation fdf OK.✅\033[0m"

clean :
	@$(RM) $(OBJS)
	@echo "\033[01;31mSuppression des objest OK.🚮\033[0m"

fclean : clean
	@$(RM) $(NAME)
	@echo "\033[01;31mSuppression de l'executable OK.🚮\033[0m"

re : fclean all

.PHONY: all re fclean clean
