/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_game_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 14:27:49 by rmarzouk          #+#    #+#             */
/*   Updated: 2024/05/07 16:10:20 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	error_msg(char *error, t_data *game, int flag)
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
	free(game->enemy1.pos);
	free(game->enemy.pos);
	if (flag != 0)
		ft_putstr_fd("ERROR :", 2);
	ft_putendl_fd(error, 2);
	exit(EXIT_FAILURE);
}

void	victory(t_data *game)
{
	game->anim_flag = 1;
	mlx_put_image_to_window(game->mlx, game->win, game->winner.xmp_ptr, \
	(game->win_w - game->winner.w) / 2, (game->win_h - game->winner.h) / 2);
	ft_putendl_fd("YOU WIN !!", 1);
}

void	loser(t_data *game)
{
	game->anim_flag = 1;
	mlx_put_image_to_window(game->mlx, game->win, game->loser.xmp_ptr, \
	(game->win_w - game->loser.w) / 2, (game->win_h - game->loser.h) / 2);
	ft_putendl_fd("YOU LOSE !!", 1);
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
	mlx_destroy_image(game->mlx, game->enemy.fire_0.xmp_ptr);
	mlx_destroy_image(game->mlx, game->enemy.fire_1.xmp_ptr);
	mlx_destroy_image(game->mlx, game->enemy.fire_2.xmp_ptr);
}
