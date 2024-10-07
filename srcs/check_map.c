/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctechy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 15:54:06 by ctechy            #+#    #+#             */
/*   Updated: 2022/11/22 15:54:07 by ctechy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/so_long.h"

static void	check_walls(t_prog *game)
{
	int	x;
	int	y;

	x = 0;
	while (game->map[x])
	{
		y = 0;
		while (game->map[x][y])
		{
			if (game->map[x][0] != '1' || game->map[x][game->x_map - 1] != '1')
				error_map("Not surround by walls", game);
			if (game->map[0][y] != '1' || game->map[game->height - 1][y] != '1')
				error_map("Not surround by walls", game);
			y++;
		}
		x++;
	}
}

static void	check_is_rect(t_prog *game)
{
	int	y_map;
	int	x_map;
	int	i;

	y_map = 0;
	x_map = 0;
	i = 0;
	while (game->map[0][i])
		i++;
	while (game->map[x_map] != 0)
	{
		y_map = ft_strlen(game->map[x_map]);
		if (y_map != i)
			error_map("Your map is not rectangular", game);
		x_map++;
	}
}

static void	check_ex_p(t_prog *game)
{
	int	x;
	int	y;

	x = 0;
	while (game->map[x])
	{
		y = 0;
		while (game->map[x][y])
		{
			if (game->map[x][y] == 'E')
				game->exit_count++;
			if (game->map[x][y] == 'P')
				game->p_count++;
			y++;
		}
		x++;
	}
}

void	do_check(t_prog *game, char *str)
{
	check_ext(str);
	check_is_rect(game);
	check_walls(game);
	check_ex_p(game);
	check_param(game);
}
