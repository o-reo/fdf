# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: eruaud <eruaud@student.le-101.fr>          +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 0017/12/28 15:26:42 by uaud         #+#   ##    ##    #+#        #
#    Updated: 2019/01/25 19:04:42 by eruaud      ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME = fdf
CC = gcc
CFLAGS = -Wall -Wextra -Werror
FUNC = main utils
SRC = $(addprefix src/, $(addsuffix .c, $(FUNC) main)) includes/fdf.h
OBJ = $(addprefix build/, $(addsuffix .o, $(FUNC)))
RED = \033[1;31m
GREEN = \033[1;92m
BLUE = \033[34;1m
YELLOW = \033[0;33m
HEADER = -I includes/ -I libft/includes/
LDLIBS = -lft -lmlx
LDFLAGS = -L libft/ -L minilibx_macos
FRAMEWORK = -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(OBJ) lib
	@echo "\033[1;31mCompiling project..."
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(HEADER) $(LDLIBS) $(LDFLAGS) $(FRAMEWORK)
	@echo "\033[1;92mSuccess !"

./build/%.o: ./src/%.c
	@echo "     $(YELLOW) → Compiling $<"
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADER)
	@echo "     $(GREEN)   OK"

lib :
	@make -C libft
	@make -C minilibx_macos

leaks: $(OBJ) lib
	@echo "\033[1;31mCompiling project..."
	@$(CC) $(CFLAGS) -fsanitize=address -fno-omit-frame-pointer -o $(NAME) $(OBJ) $(HEADER) $(LDLIBS) $(LDFLAGS) $(FRAMEWORK)
	@echo "\033[1;92mSuccess !"

norm :
	@norminette $(SRC) $()

cclean:
	@/bin/rm -f $(OBJ_CHECK) $(CHECK_NAME)

clean:
	@/bin/rm -f $(OBJ)
	@echo "  $(YELLOW)OBJ files have been deleted."

fclean:
	@/bin/rm -f $(OBJ) $(NAME)
	@echo "  $(YELLOW)$(NAME) and OBJ files have been deleted."

re: fclean $(NAME)

.PHONY = all clean fclean re norm lib
