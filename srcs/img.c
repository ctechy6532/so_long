/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctechy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 15:40:35 by ctechy            #+#    #+#             */
/*   Updated: 2022/11/22 15:40:36 by ctechy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	img_init(t_prog *game)
{
	game->img.player = mlx_xpm_file_to_image(game->mlx_ptr, "./img/player.xpm",
			&game->img.height, &game->img.width);
	game->img.wall = mlx_xpm_file_to_image(game->mlx_ptr, "./img/wall.xpm",
			&game->img.height, &game->img.width);
	game->img.coin = mlx_xpm_file_to_image(game->mlx_ptr, "./img/coin.xpm",
			&game->img.height, &game->img.width);
	game->img.grass = mlx_xpm_file_to_image(game->mlx_ptr, "./img/grass.xpm",
			&game->img.height, &game->img.width);
	game->img.exit = mlx_xpm_file_to_image(game->mlx_ptr, "./img/escape.xpm",
			&game->img.height, &game->img.width);
}

static int	img_put_utils(int y_map, int x_map, char c, t_prog *game)
{
	if (c == '1')
		mlx_put_image_to_window(game->mlx_ptr, game->win,
			game->img.wall, x_map * 32, y_map * 32);
	if (c == '0' || c == 'E')
		mlx_put_image_to_window(game->mlx_ptr, game->win,
			game->img.grass, x_map * 32, y_map * 32);
	if (c == 'P')
		mlx_put_image_to_window(game->mlx_ptr, game->win,
			game->img.player, x_map * 32, y_map * 32);
	if (game->coin_nb == 0)
		mlx_put_image_to_window(game->mlx_ptr, game->win, game->img.exit,
			game->exit_x * 32, game->exit_y * 32);
	if (c == 'C')
		mlx_put_image_to_window(game->mlx_ptr, game->win,
			game->img.coin, x_map * 32, y_map * 32);
	return (0);
}

int	img_put(t_prog *game)
{
	int	y_map;
	int	x_map;

	y_map = 0;
	while (game->map[y_map])
	{
		x_map = 0;
		while (game->map[y_map][x_map])
		{
			img_put_utils(y_map, x_map, game->map[y_map][x_map], game);
			x_map++;
		}
		y_map++;
	}
	return (0);
}
