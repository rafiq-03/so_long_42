/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 14:27:55 by rmarzouk          #+#    #+#             */
/*   Updated: 2024/05/07 12:39:42 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	find_paths(char **map, int new_x, int new_y);
static void	_check_params(t_data *game, char **map);
static void	loop_in_map(t_data *game, t_map tmp, char **map);
static void	check_tmp(t_map tmp);

void	find_path(t_data *game)
{
	char	**tmp_map;
	t_pos	position;
	int		i;

	i = 0;
	position.x = game->p_position.x;
	position.y = game->p_position.y;
	tmp_map = malloc((game->map.rows + 1) * sizeof(char *));
	while (game->map.map[i])
	{
		tmp_map[i] = ft_strdup(game->map.map[i]);
		i++;
	}
	tmp_map[i] = NULL;
	find_paths(tmp_map, position.x, position.y);
	_check_params(game, tmp_map);
	i = 0;
	while (tmp_map[i])
		free(tmp_map[i++]);
	free(tmp_map);
}

static void	find_paths(char **map, int new_x, int new_y)
{
	if (map[new_x][new_y] == WALL || map[new_x][new_y] == ' '
		|| map[new_x][new_y] == 'X')
		return ;
	if (map[new_x][new_y] == FLOOR || map[new_x][new_y] == COINS
		|| map[new_x][new_y] == PLAYER)
	{
		map[new_x][new_y] = ' ';
	}
	if (map[new_x][new_y] == MAP_EXIT)
	{
		map[new_x][new_y] = WALL;
		return ;
	}
	find_paths(map, new_x - 1, new_y);
	find_paths(map, new_x + 1, new_y);
	find_paths(map, new_x, new_y + 1);
	find_paths(map, new_x, new_y - 1);
}

static void	_check_params(t_data *game, char **map)
{
	t_map	tmp;

	tmp.coins = 0;
	tmp.exit = 0;
	tmp.fire = 0;
	tmp.cols = -1;
	tmp.enemy = 0;
	loop_in_map(game, tmp, map);
	check_tmp(tmp);
}

static void	loop_in_map(t_data *game, t_map tmp, char **map)
{
	while (++tmp.cols < game->map.rows)
	{
		tmp.rows = -1;
		while (++tmp.rows < game->map.cols)
		{
			if (!ft_strchr("CPE01XM ", map[tmp.cols][tmp.rows]))
				error("find path error");
			else if (map[tmp.cols][tmp.rows] == COINS)
				tmp.coins++;
			else if (map[tmp.cols][tmp.rows] == MAP_EXIT)
				tmp.exit++;
			else if (map[tmp.cols][tmp.rows] == FIRE)
			{
				game->enemy.pos[tmp.fire].x = tmp.cols;
				game->enemy.pos[tmp.fire++].y = tmp.rows;
			}
			else if (map[tmp.cols][tmp.rows] == ENEMY)
			{
				game->enemy1.pos[tmp.enemy].x = tmp.cols;
				game->enemy1.pos[tmp.enemy++].y = tmp.rows;
			}
		}
	}
}

static void	check_tmp(t_map tmp)
{
	if (tmp.exit != 0)
		error("The player can't exit the map");
	if (tmp.coins != 0)
		error("The player can't collect all coins !!");
}
