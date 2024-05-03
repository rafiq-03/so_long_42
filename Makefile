# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmarzouk <rmarzouk@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/02 23:16:38 by rmarzouk          #+#    #+#              #
#    Updated: 2024/04/30 21:30:14 by rmarzouk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= so_long

### FLAGS

CC=gcc
CFLAGS= -Wall -Wextra -Werror
MLX_FLAGS= -lmlx -framework OpenGL -framework AppKit

### GET_NEXT_LINE

GNL= get_next_line
GNL_DIR= utils/gnl
GNL_SRC= $(GNL_DIR)/get_next_line.c $(GNL_DIR)/get_next_line_utils.c
GNL_OBJ= $(GNL_DIR)/get_next_line.o $(GNL_DIR)/get_next_line_utils.o

### LIBFT

LIBFT = libft.a
LIBFT_DIR = utils/libft

### UTILS

UTILS_DIR = mandatory/
UTILS_S = $(addprefix $(UTILS_DIR),		\
						fill_map.c 		\
						map_check.c 	\
						init_game.c 	\
						render_map.c 	\
						hooks.c 		\
						find_path.c 	\
						close_game.c)

UTILS_O = $(UTILS_S:.c=.o)

### B_UTILS

B_UTILS_DIR = Bonus/
B_UTILS_S = $(addprefix $(B_UTILS_DIR),		\
						fill_map_bonus.c 	\
						map_check_bonus.c 	\
						init_game_bonus.c 	\
						render_map_bonus.c 	\
						Put_strings_bouns.c	\
						hooks_bonus.c 		\
						find_path_bonus.c 	\
						animation.c			\
						close_game_bonus.c)

B_UTILS_O = $(B_UTILS_S:.c=.o)

all: $(NAME)

$(NAME):mandatory/$(NAME).c $(LIBFT) $(GNL) $(UTILS_O)
	@$(CC) $(CFLAGS) $(LIBFT_DIR)/$(LIBFT) $(GNL_OBJ) $(UTILS_O) \
	mandatory/$(NAME).c $(MLX_FLAGS) -o $(NAME)

$(GNL): $(GNL_OBJ)

$(LIBFT):
	@echo "Libft.."
	@make -C $(LIBFT_DIR)

%.o:%.c so_long.h
	${CC} ${CFLAGS} -c $< -o $@

bonus:Bonus/so_long_bonus.c $(LIBFT) $(GNL) $(B_UTILS_O)
	@$(CC) $(CFLAGS)  $(LIBFT_DIR)/$(LIBFT) $(GNL_OBJ) $(B_UTILS_O) \
	Bonus/so_long_bonus.c $(MLX_FLAGS) -o so_long_bonus

clean:
	@echo "$(RED)Cleanin object files ...$(RESET)"
	@make -C $(LIBFT_DIR) clean
	@rm -f $(GNL_OBJ)
	@rm -f $(UTILS_O)
	@rm -f $(B_UTILS_O)
	@echo "DONE .."
	

fclean: clean
	@make -C $(LIBFT_DIR) fclean
	@echo "Cleaning so_long"
	@rm $(NAME)
	@rm so_long_bonus
re: fclean all

.PHONY: clean fclean re all
