/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 17:33:22 by rmarzouk          #+#    #+#             */
/*   Updated: 2024/04/30 20:02:52 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	animation(t_data *game)
{
	static int	count = 0;
	int			i;

	i = game->map.fire;
	if (game->anim_flag == 1)
		return (0);
	if (count == 0)
		while (i--)
			put_img_to_win(game, game->enemy.fire_0, game->enemy.pos[i].y,
				game->enemy.pos[i].x);
	else if (count == 2000)
		while (i--)
			put_img_to_win(game, game->enemy.fire_1, game->enemy.pos[i].y,
				game->enemy.pos[i].x);
	else if (count == 4000)
		while (i--)
			put_img_to_win(game, game->enemy.fire_2, game->enemy.pos[i].y,
				game->enemy.pos[i].x);
	count++;
	if (count == 6000)
		count = 0;
	return (0);
}
// int		not_here(t_data *game)
// {
// 	int	i;
// 	t_pos	pos;

// 	i = game->map.fire;
// 	while (i--)
// 	{
// 		pos.x = game->enemy.pos[i].x;
// 		pos.y = game->enemy.pos[i].y;
// 		if (pos.x)
// 	}
// }
