/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 13:30:29 by rmarzouk          #+#    #+#             */
/*   Updated: 2024/05/07 15:45:50 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	main(int ac, char **av)
{
	t_data	game;

	check_command_line(ac, av);
	map_fill(&game, av);
	init_params(&game);
	map_check(&game);
	find_path(&game);
	init_mlx(&game);
	init_imgs(&game);
	render_map(&game);
	put_string(&game);
	mlx_hook(game.win, 2, 0, key_hooks, &game);
	mlx_hook(game.win, 17, 0, mouse_hook, &game);
	mlx_loop_hook(game.mlx, animation, &game);
	mlx_loop(game.mlx);
	return (0);
}
