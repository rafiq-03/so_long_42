/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 14:25:20 by rmarzouk          #+#    #+#             */
/*   Updated: 2024/04/30 11:02:22 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	error(char *error)
{
	ft_putstr_fd("\x1B[31mERROR :", 2);
	ft_putendl_fd(error, 2);
	exit(EXIT_FAILURE);
}

void	map_fill(t_data *game, char **av)
{
	char	*line;
	char	*tmp_map;
	int		fd;

	game->map.rows = 0;
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		error("File doesn't exist");
	tmp_map = ft_strdup("");
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (line[0] == '\n')
			error("Consecutive newlines");
		_strjoin(&tmp_map, line);
		free(line);
		game->map.rows++;
	}
	game->map.map = ft_split(tmp_map, '\n');
	game->flag = 1;
	free(tmp_map);
}
