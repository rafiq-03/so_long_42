/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 14:27:37 by rmarzouk          #+#    #+#             */
/*   Updated: 2024/05/07 13:18:50 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	render_map(t_data *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < game->map.rows)
	{
		j = 0;
		while (j < game->map.cols)
		{
			load_img(game, game->map.map[i][j], i, j);
			j++;
		}
		i++;
	}
}

void	load_img(t_data *game, char param, int i, int j)
{
	if (param == PLAYER)
		render_player(game, j, i);
	else if (param == WALL)
		put_img_to_win(game, game->wall, j, i);
	else if (param == FLOOR)
		put_img_to_win(game, game->floor, j, i);
	else if (param == COINS)
		put_img_to_win(game, game->coins, j, i);
	else if (param == ENEMY)
		put_img_to_win(game, game->enemy1.enemy, j, i);
	else if (param == MAP_EXIT)
	{
		if (game->map.coins == 0)
			put_img_to_win(game, game->exit_open, j, i);
		else
			put_img_to_win(game, game->exit_close, j, i);
	}
}

void	render_player(t_data *game, int j, int i)
{
	if (game->player == 1)
		put_img_to_win(game, game->player_front, j, i);
	else if (game->player == 2)
		put_img_to_win(game, game->player_left, j, i);
	else if (game->player == 3)
		put_img_to_win(game, game->player_right, j, i);
	else if (game->player == 4)
		put_img_to_win(game, game->player_back, j, i);
}

void	put_img_to_win(t_data *game, t_img img, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, img.xmp_ptr, x * img.w,
		y * img.h);
}
