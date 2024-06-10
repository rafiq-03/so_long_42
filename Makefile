# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmarzouk <rmarzouk@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/02 23:16:38 by rmarzouk          #+#    #+#              #
#    Updated: 2024/05/07 15:48:12 by rmarzouk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= so_long
BNAME= so_long_bonus

### FLAGS

CC=cc
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
						so_long.c		\
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
						so_long_bonus.c		\
						fill_map_bonus.c 	\
						map_check_bonus.c 	\
						init_game_bonus.c 	\
						render_map_bonus.c 	\
						Put_strings_bouns.c	\
						hooks_bonus.c 		\
						find_path_bonus.c 	\
						animation_bonus.c	\
						close_game_bonus.c \
						fill_enemy_ar_bonus.c)

B_UTILS_O = $(B_UTILS_S:.c=.o)

all:$(NAME)

$(NAME):$(GNL_OBJ) $(UTILS_O)
	make -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) -L$(LIBFT_DIR) -lft $(GNL_OBJ) $(UTILS_O) $(MLX_FLAGS) -o $(NAME)

bonus:$(BNAME)

$(BNAME):$(GNL_OBJ) $(B_UTILS_O)
	make -C $(LIBFT_DIR)
	$(CC) $(CFLAGS)  -L$(LIBFT_DIR) -lft $(GNL_OBJ) $(B_UTILS_O) $(MLX_FLAGS) -o $(BNAME)

%.o:%.c mandatory/so_long.h Bonus/so_long_bonus.h 
	${CC} ${CFLAGS} -c $< -o $@

clean:
	@echo "$(RED)Cleanin object files ...$(RESET)"
	@make -C $(LIBFT_DIR) fclean
	@rm -f $(GNL_OBJ)
	@rm -f $(UTILS_O)
	@rm -f $(B_UTILS_O)
	@echo "DONE .."
	

fclean: clean
	@make -C $(LIBFT_DIR) fclean
	@echo "Cleaning so_long"
	@rm -f $(NAME)
	@rm -f so_long_bonus
re: fclean all

.PHONY: clean fclean re all