/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 17:33:22 by rmarzouk          #+#    #+#             */
/*   Updated: 2024/05/07 15:42:00 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	animation(t_data *game)
{
	static int	count = 0;
	static int	a = 0;
	int			i;

	i = game->map.fire;
	if (game->anim_flag == 1)
		return (0);
	if (count == 0 || count == 8000 || count == 16000)
		a = anim(game, i, a, 0);
	else if (count == 2000 || count == 10000 || count == 18000)
		a = anim(game, i, a, 1);
	else if (count == 4000 || count == 12000 || count == 20000)
		a = anim(game, i, a, 2);
	if (a == game->map.enemy)
		a = 0;
	if (count == 20000)
		count = 0;
	count++;
	return (0);
}

int	anim(t_data *game, int i, int a, int flag)
{
	if (flag == 0)
	{
		while (i--)
			put_img_to_win(game, game->enemy.fire_0, game->enemy.pos[i].y,
				game->enemy.pos[i].x);
	}
	else if (flag == 1)
	{
		while (i--)
			put_img_to_win(game, game->enemy.fire_1, game->enemy.pos[i].y,
				game->enemy.pos[i].x);
	}
	else if (flag == 2)
	{
		while (i--)
			put_img_to_win(game, game->enemy.fire_2, game->enemy.pos[i].y,
				game->enemy.pos[i].x);
	}
	moves(game, a++);
	return (a);
}

int	moves(t_data *game, int n)
{
	t_pos		pos;

	if (game->map.enemy == 0)
		return (1); 
	pos.x = game->enemy1.pos[n].x;
	pos.y = game->enemy1.pos[n].y;
	if (game->map.map[pos.x][pos.y + 1] == FLOOR
	|| game->map.map[pos.x][pos.y + 1] == PLAYER)
	{
		pos.y++;
		ft_move(game, pos, n);
	}
	else if (game->map.map[pos.x][pos.y - 1] == FLOOR
		|| game->map.map[pos.x][pos.y - 1] == PLAYER)
	{
		pos.y--;
		ft_move(game, pos, n);
	}
	return (0);
}

void	ft_move(t_data *game, t_pos new, int n)
{
	t_pos	old;

	ft_wait();
	old.x = game->enemy1.pos[n].x;
	old.y = game->enemy1.pos[n].y;
	if (game->map.map[new.x][new.y] == PLAYER)
	{
		game->p_position.x = 0;
		game->p_position.x = 0;
		game->map.map[old.x][old.y] = FLOOR;
		game->map.map[new.x][new.y] = ENEMY;
		loser(game);
	}
	game->map.map[old.x][old.y] = FLOOR;
	game->map.map[new.x][new.y] = ENEMY;
	put_img_to_win(game, game->enemy1.enemy, new.y, new.x);
	put_img_to_win(game, game->floor, old.y, old.x);
	mlx_do_sync(game->mlx);
	game->enemy1.pos[n].x = new.x;
	game->enemy1.pos[n].y = new.y;
	ft_wait();
}

void	ft_wait(void)
{
	static int	i = 0;

	while (i < 9000)
	{
		i++;
	}
	if (i >= 9000)
		i = 0;
}
