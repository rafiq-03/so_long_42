/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 13:33:15 by rmarzouk          #+#    #+#             */
/*   Updated: 2024/05/07 16:09:19 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	mouse_hook(t_data *game)
{
	error_msg("Game closed : Clicking on the cross", game, 0);
	return (0);
}

int	key_hooks(int key_code, t_data *game)
{
	if (game->p_position.x != 0 && game->p_position.y != 0)
	{
		if (key_code == W_KEY || key_code == UP_KEY)
			player_moves(game, game->p_position.x - 1, game->p_position.y, 4);
		if (key_code == S_KEY || key_code == DOWN_KEY)
			player_moves(game, game->p_position.x + 1, game->p_position.y, 1);
		if (key_code == D_KEY || key_code == RIGHT_KEY)
			player_moves(game, game->p_position.x, game->p_position.y + 1, 3);
		if (key_code == A_KEY || key_code == LEFT_KEY)
			player_moves(game, game->p_position.x, game->p_position.y - 1, 2);
	}
	if (key_code == ESC_KEY)
		error_msg("Game closed : Pressing ESC", game, 0);
	return (0);
}

void	player_moves(t_data *game, int new_px, int new_py, int status)
{
	t_pos	old;

	old.x = game->p_position.x;
	old.y = game->p_position.y;
	game->player = status;
	if ((game->map.map[new_px][new_py] == MAP_EXIT && game->map.coins == 0)
		|| game->map.map[new_px][new_py] == FIRE
		|| game->map.map[new_px][new_py] == ENEMY)
	{
		game->map.map[old.x][old.y] = FLOOR;
		load_img(game, game->map.map[old.x][old.y], old.x, old.y);
		game->p_position.x = 0;
		game->p_position.y = 0;
		if (game->map.map[new_px][new_py] == MAP_EXIT)
			victory(game);
		else
			loser(game);
	}
	if (game->map.map[new_px][new_py] == FLOOR 
		|| game->map.map[new_px][new_py] == COINS)
		check_floor_coin(game, new_px, new_py, old);
}

void	check_floor_coin(t_data *game, int new_px, int new_py, t_pos old)
{
	if (game->map.map[new_px][new_py] == COINS)
		game->map.coins--;
	game->p_position.x = new_px;
	game->p_position.y = new_py;
	game->map.map[new_px][new_py] = PLAYER;
	game->map.map[old.x][old.y] = FLOOR;
	game->movements++;
	render_map(game);
	put_string(game);
}
