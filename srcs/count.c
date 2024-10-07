/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctechy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 15:50:52 by ctechy            #+#    #+#             */
/*   Updated: 2022/11/22 15:50:53 by ctechy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/so_long.h"

void	player_pos(t_prog *game)
{
	int	x_map;
	int	y_map;

	x_map = 0;
	while (game->map[x_map])
	{
		y_map = 0;
		while (game->map[x_map][y_map])
		{
			if (game->map[x_map][y_map] == 'P')
			{
				game->player_y = x_map;
				game->player_x = y_map;
			}
			y_map++;
		}
		x_map++;
	}
}

void	exit_pos(t_prog *game)
{
	int	x_map;
	int	y_map;

	x_map = 0;
	while (game->map[x_map])
	{
		y_map = 0;
		while (game->map[x_map][y_map])
		{
			if (game->map[x_map][y_map] == 'E')
			{
				game->exit_x = y_map;
				game->exit_y = x_map;
			}
			y_map++;
		}
		x_map++;
	}
}

void	coin_nb(t_prog *game)
{
	int	x_map;
	int	y_map;

	x_map = 0;
	while (game->map[x_map])
	{
		y_map = 0;
		while (game->map[x_map][y_map])
		{
			if (game->map[x_map][y_map] == 'C')
				game->coin_nb++;
			y_map++;
		}
		x_map++;
	}
}

void	count_make(t_prog *game)
{
	coin_nb(game);
	player_pos(game);
	exit_pos(game);
}
