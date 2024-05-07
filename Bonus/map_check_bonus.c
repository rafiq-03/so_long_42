/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 14:27:04 by rmarzouk          #+#    #+#             */
/*   Updated: 2024/05/07 15:32:37 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	map_check(t_data *game)
{
	if (game->map.cols == 0)
		error("Empty Line");
	if (game->map.cols > 40 || game->map.rows > 20)
		error("Map is to big ..");
	check_rows(game);
	check_cols(game);
	check_params(game);
	game->enemy.pos = malloc(game->map.fire * sizeof(t_pos));
	game->enemy1.pos = malloc(game->map.enemy * sizeof(t_pos));
}

void	check_rows(t_data *game)
{
	int	i;

	i = 0;
	while (i < game->map.cols)
	{
		if (game->map.map[0][i] != WALL)
			error("Map is not surrounded by walls");
		if (game->map.map[game->map.rows - 1][i] != WALL)
			error("Map is not surrounded by walls");
		i++;
	}
}

void	check_cols(t_data *game)
{
	int	i;

	i = 0;
	while (i < game->map.rows)
	{
		if (game->map.map[i][0] != WALL)
			error("map is not surrounded by walls");
		if (game->map.map[i][game->map.cols - 1] != WALL)
			error("map is not surrounded by walls");
		i++;
	}
}

void	loop_in_map(t_data *game, int i)
{
	int		j;

	while (++i < game->map.rows)
	{
		j = -1;
		while (++j < game->map.cols)
		{
			if (!ft_strchr("CPE01XM", game->map.map[i][j]))
				error("Invalid map's parameter ...");
			else if (game->map.map[i][j] == PLAYER)
			{
				game->map.player++;
				game->p_position.x = i;
				game->p_position.y = j;
			}
			else if (game->map.map[i][j] == COINS)
				game->map.coins++;
			else if (game->map.map[i][j] == MAP_EXIT)
				game->map.exit++;
			else if (game->map.map[i][j] == FIRE)
				game->map.fire++;
			else if (game->map.map[i][j] == ENEMY)
				game->map.enemy++;
		}
	}
}

void	check_params(t_data *game)
{
	int	i;

	i = -1;
	loop_in_map(game, i);
	if (game->map.player == 0)
		error("Player doesn't exist");
	else if (game->map.player > 1)
		error("There is more than one player");
	if (game->map.coins == 0)
		error("There is no coins to collect");
	if (game->map.exit == 0)
		error("There in no exit in this map");
	else if (game->map.exit > 1)
		error("There is more than one exit map");
}
