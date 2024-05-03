/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 14:27:49 by rmarzouk          #+#    #+#             */
/*   Updated: 2024/04/30 20:06:26 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_msg(char *error, t_data *game)
{
	int	i;

	i = 0;
	if (game->flag == 1)
	{
		while (game->map.map[i])
			free(game->map.map[i++]);
		free(game->map.map);
	}
	destroy_imgs(game);
	mlx_destroy_window(game->mlx, game->win);
	free(game->mlx);
	ft_putstr_fd("\x1B[31m ERROR :", 2);
	ft_putendl_fd(error, 2);
	exit(EXIT_FAILURE);
}

void	victory(t_data *game)
{
	mlx_put_image_to_window(game->mlx, game->win, game->winner.xmp_ptr, \
	(game->win_w - game->winner.w) / 2, (game->win_h - game->winner.h) / 2);
	ft_putendl_fd("YOU WIN", 1);
}

void	destroy_imgs(t_data *game)
{
	mlx_destroy_image(game->mlx, game->player_front.xmp_ptr);
	mlx_destroy_image(game->mlx, game->player_back.xmp_ptr);
	mlx_destroy_image(game->mlx, game->player_right.xmp_ptr);
	mlx_destroy_image(game->mlx, game->player_left.xmp_ptr);
	mlx_destroy_image(game->mlx, game->exit_open.xmp_ptr);
	mlx_destroy_image(game->mlx, game->exit_close.xmp_ptr);
	mlx_destroy_image(game->mlx, game->wall.xmp_ptr);
	mlx_destroy_image(game->mlx, game->coins.xmp_ptr);
	mlx_destroy_image(game->mlx, game->floor.xmp_ptr);
}
