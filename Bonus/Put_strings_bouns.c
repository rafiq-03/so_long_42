/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Put_strings_bouns.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 20:40:16 by rmarzouk          #+#    #+#             */
/*   Updated: 2024/04/25 22:28:31 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	put_string(t_data *game)
{
	char	*moves;
	char	*coins;
	char	*str;

	moves = ft_itoa(game->movements);
	coins = ft_itoa(game->map.coins);
	str = ft_strjoin("Movments   :", moves);
	mlx_string_put(game->mlx, game->win, 10, 4, 0xffffff, str);
	free(str);
	str = ft_strjoin("Left coins :", coins);
	mlx_string_put(game->mlx, game->win, 10, 25, 0xffffff, str);
	free(moves);
	free(coins);
	free(str);
}
