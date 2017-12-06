# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ppatel <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/14 17:32:33 by ppatel            #+#    #+#              #
#    Updated: 2017/01/31 18:11:06 by ppatel           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

NAME = fractol

FLAGS = -Wall -Wextra -Werror

SDIR = srcs

ODIR = objs

SRC = $(SDIR)/main.c \
	  $(SDIR)/fractal.c \
	  $(SDIR)/hook.c

OBJ = $(SRC:$(SDIR)/%.c=$(ODIR)/%.o)

HDRS = -I./minilibx/ \
	   -I./includes

LIBFT = libft/libft.a

LIBS = -lmlx \
	   -L./libft/ -lft

all : $(NAME)

$(NAME): $(ODIR) $(LIBFT) $(OBJ)
	@$(CC) $(FLAGS) -framework OpenGL -framework Appkit $(LIBS) -o $@ $(OBJ)
	@echo "Executable created."

$(ODIR):
	@mkdir objs

$(ODIR)/%.o: $(SDIR)/%.c
	@$(CC) $(FLAGS) -c $< $(HDRS) -o $@
	@echo "Object created."

$(LIBFT):
	@make -C libft/

clean:
	@rm -rf $(ODIR)
	@echo "Objects deleted."

fclean: clean
	@rm -rf $(NAME)
	@make fclean -C libft/
	@echo "Executable deleted."

re: fclean all

.PHONY: all clean fclean re
