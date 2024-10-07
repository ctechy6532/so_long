/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctechy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 15:35:24 by ctechy            #+#    #+#             */
/*   Updated: 2022/11/22 15:35:52 by ctechy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	check_move(t_prog *game, int x_map, int y_map, int keycode)
{
	if (game->map[y_map][x_map] == '1')
		return (0);
	else if (game->map[y_map][x_map] == 'C')
		game->coin_nb--;
	else if (game->map[y_map][x_map] == 'E' && game->coin_nb == 0)
	{
		ft_printf("GG you just finish the game with %d movements\n",
			game->move++);
		game->finish = 1;
		free_img(game);
	}
	else if (keycode != 13 && keycode != 0 && keycode != 2 && keycode != 1)
		return (0);
	return (1);
}

static void	move(t_prog *game, int x_map, int y_map, int keycode)
{
	int	y_map_l;
	int	x_map_l;
	int	valid;

	valid = check_move(game, x_map, y_map, keycode);
	x_map_l = game->player_x;
	y_map_l = game->player_y;
	if (valid == 1)
	{
		game->map[y_map_l][x_map_l] = '0';
		game->player_y = y_map;
		game->player_x = x_map;
		game->map[y_map][x_map] = 'P';
		ft_printf("Movements: %d\n", game->move++);
	}
}

int	key_hook(int keycode, t_prog *game)
{
	int	y_map;
	int	x_map;

	x_map = game->player_x;
	y_map = game->player_y;
	if (keycode == 13)
		y_map--;
	else if (keycode == 0)
		x_map--;
	else if (keycode == 2)
		x_map++;
	else if (keycode == 1)
		y_map++;
	if (game->coin_nb == 0)
		game->map[game->exit_y][game->exit_x] = 'E';
	if (game->finish == 0)
		move(game, x_map, y_map, keycode);
	if (keycode == 53)
		free_img(game);
	return (0);
}
