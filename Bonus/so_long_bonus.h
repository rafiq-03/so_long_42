/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 13:33:48 by rmarzouk          #+#    #+#             */
/*   Updated: 2024/05/07 16:15:48 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

/*------------includes----------*/

# include <mlx.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../utils/gnl/get_next_line.h"
# include "../utils/Libft/libft.h"

/*------------defines----------*/

# define IMG_HEIGHT			64
# define IMG_WIDTH			64

/*_____________________________*/

# define WALL				49 //'1'
# define FLOOR 				48 //'0'
# define COINS  			67 //'C'
# define PLAYER				80 //'P'
# define MAP_EXIT 		 	69 //'E'
# define FIRE 		 		88 //'X'
# define ENEMY 		 		77 //'M'

# define W_KEY			13
# define A_KEY			0
# define S_KEY			1
# define D_KEY			2

# define UP_KEY			126
# define LEFT_KEY		123
# define RIGHT_KEY		124
# define DOWN_KEY		125

# define ESC_KEY			53

# define WALL_XPM			"textures/wall.xpm"
# define FLOOR_XPM			"textures/space.xpm"
# define COINS_XPM			"textures/collect.xpm"
# define PLAYER_FRONT_XPM	"textures/player_front.xpm"
# define PLAYER_LEFT_XPM	"textures/player_left.xpm"
# define PLAYER_RIGHT_XPM	"textures/player_right.xpm"
# define PLAYER_BACK_XPM	"textures/player_back.xpm"
# define OPEN_EXIT_XPM		"textures/exit_2.xpm"
# define EXIT_CLOSED_XPM	"textures/exit_1.xpm"
# define WINNER_XPM			"textures/winner.xpm"
# define LOSER_XPM			"textures/loser.xpm"
// enemy frames
# define FIRE_0_XPM			"textures/fire/fire0.xpm"
# define FIRE_1_XPM			"textures/fire/fire1.xpm"
# define FIRE_2_XPM			"textures/fire/fire2.xpm"

# define ENEMY_XPM			"textures/enemy.xpm"

/*------------structures----------*/

typedef struct s_pos
{
	int	x;
	int	y;
}	t_pos;

typedef struct s_img
{
	void		*xmp_ptr;
	int			w;
	int			h;
}	t_img;

typedef struct s_map
{
	char	**map;
	int		rows;
	int		cols;
	int		exit;
	int		player;
	int		coins;
	int		fire;
	int		enemy;
}	t_map;

typedef struct s_enemy
{
	t_img	fire_0;
	t_img	fire_1;
	t_img	fire_2;
	t_pos	*pos;

}	t_enemy;
typedef struct s_enemy1
{
	t_img	enemy;
	t_pos	*pos;

}	t_enemy1;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	int			movements;
	int			win_w;
	int			win_h;
	int			player;

	t_img		wall;
	t_img		floor;
	t_img		exit_open;
	t_img		exit_close;
	t_img		coins;
	t_img		player_front; 
	t_img		player_back; 
	t_img		player_left;
	t_img		player_right;
	t_img		winner;
	t_img		loser;
	t_pos		p_position;
	t_pos		exit_p;
	t_map		map; 
	int			flag;
	int			anim_flag;
	t_enemy		enemy;
	t_enemy1	enemy1;

}	t_data;

/*------------prototypes----------*/

void	check_command_line(int ac, char **av);
void	map_fill(t_data *game, char **av);

void	init_params(t_data *game);
void	init_mlx(t_data *game);
void	init_imgs(t_data *game);
t_img	new_img(char *path, t_data *game);

void	map_check(t_data *game);
void	check_rows(t_data *game);
void	check_cols(t_data *game);
void	check_params(t_data *game);
void	is_valid(t_data *game);
void	find_path(t_data *game);

void	put_img_to_win(t_data *game, t_img img, int x, int y);
void	load_img(t_data *game, char param, int i, int j);
void	render_player(t_data *game, int i, int j);
void	render_map(t_data *game);
int		animation(t_data *game);

int		moves(t_data *game, int n);
void	ft_move(t_data *game, t_pos new, int n);
void	ft_wait(void);
int		anim(t_data *game, int i, int a, int flag);

void	player_moves(t_data *game, int x, int y, int status);
int		key_hooks(int key_code, t_data *game);
int		mouse_hook(t_data *game);
void	check_floor_coin(t_data *game, int new_px, int new_py, t_pos old);
void	put_string(t_data *game);

void	error(char *error);
void	error_msg(char *error, t_data *game, int flag);

void	destroy_imgs(t_data *game);
void	victory(t_data *game);
void	loser(t_data *game);

#endif
