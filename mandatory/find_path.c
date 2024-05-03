/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 14:27:55 by rmarzouk          #+#    #+#             */
/*   Updated: 2024/04/29 14:13:56 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	find_paths(char **map, int new_x, int new_y);
static void	_check_params(t_data *game, char **map);

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
	if (map[new_x][new_y] == WALL || map[new_x][new_y] == ' ')
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
	int	i;
	int	j;
	int	coins;
	int	exit;

	coins = 0;
	exit = 0;
	i = -1;
	while (++i < game->map.rows)
	{
		j = -1;
		while (++j < game->map.cols)
		{
			if (!ft_strchr("CPE01 ", map[i][j]))
				error("find path error");
			else if (map[i][j] == COINS)
				coins++;
			else if (map[i][j] == MAP_EXIT)
				exit++;
		}
	}
	if (exit != 0)
		error("The player can't exit the map");
	if (coins != 0)
		error("The player can't collect all coins !!");
}
