/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 13:33:42 by rmarzouk          #+#    #+#             */
/*   Updated: 2024/05/07 13:20:03 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	check_command_line(int ac, char **av)
{
	int	len;

	len = ft_strlen(av[1]);
	if (ac != 2)
		error("Invaide Number of Arguments");
	if (!ft_strnstr(&av[1][len - 4], ".ber", 4))
		error("Invalid Map's Name");
}

void	init_params(t_data *game)
{
	game->map.coins = 0;
	game->map.exit = 0;
	game->map.player = 0;
	game->movements = 0;
	game->map.enemy = 0;
	game->map.fire = 0;
	game->map.cols = ft_strlen(game->map.map[0]);
	game->win_w = game->map.cols * IMG_WIDTH;
	game->win_h = game->map.rows * IMG_HEIGHT;
	game->player = 1;
	game->anim_flag = 0;
}

void	init_mlx(t_data *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		error("mlx_init");
	game->win = mlx_new_window(game->mlx, game->win_w, game->win_h, 
			"So_long_bonus");
	if (!game->win)
	{
		free(game->mlx);
		error("mlx_new_indow");
	}
}

void	init_imgs(t_data *game)
{
	game->player_front = new_img(PLAYER_FRONT_XPM, game);
	game->player_back = new_img(PLAYER_BACK_XPM, game);
	game->player_right = new_img(PLAYER_RIGHT_XPM, game);
	game->player_left = new_img(PLAYER_LEFT_XPM, game);
	game->exit_open = new_img(OPEN_EXIT_XPM, game);
	game->exit_close = new_img(EXIT_CLOSED_XPM, game);
	game->coins = new_img(COINS_XPM, game);
	game->wall = new_img(WALL_XPM, game);
	game->floor = new_img(FLOOR_XPM, game);
	game->winner = new_img(WINNER_XPM, game);
	game->loser = new_img(LOSER_XPM, game);
	game->enemy.fire_0 = new_img(FIRE_0_XPM, game);
	game->enemy.fire_1 = new_img(FIRE_1_XPM, game);
	game->enemy.fire_2 = new_img(FIRE_2_XPM, game);
	game->enemy1.enemy = new_img(ENEMY_XPM, game);
}

t_img	new_img(char *path, t_data *game)
{
	t_img	new_img;

	new_img.xmp_ptr = mlx_xpm_file_to_image(game->mlx, path, &new_img.w,
			&new_img.h);
	if (!new_img.xmp_ptr)
		error("IMG FILE DOESN'T EXIST");
	return (new_img);
}
