/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctechy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 16:14:47 by ctechy            #+#    #+#             */
/*   Updated: 2022/11/23 16:14:48 by ctechy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/so_long.h"

void	check_param(t_prog *game)
{
	int	x;
	int	y;

	x = 0;
	while (game->map[x])
	{
		y = 0;
		while (game->map[x][y])
		{
			if (game->map[x][y] != 'E' && game->map[x][y] != '0' &&
			game->map[x][y] != 'C' && game->map[x][y] != '1' &&
			game->map[x][y] != 'P')
				error_map("Need to have E 0 C 1 P in map", game);
			if (game->coin_nb == 0)
				error_map("Need at least 1 coin", game);
			if (game->p_count != 1)
				error_map("Need 1 player only", game);
			if (game->exit_count != 1)
				error_map("Need 1 exit only", game);
			y++;
		}
		x++;
	}
}

void	check_ext(char *str)
{
	int	i;
	int	size;

	i = 0;
	size = ft_strlen(str);
	while (str[i])
	{
		if (str[i] == '.')
		{
			if (ft_strnstr(str, ".ber", size))
				return ;
		}
		i++;
	}
	error_msg("Not .ber file");
}
