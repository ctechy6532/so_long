/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctechy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 15:51:50 by ctechy            #+#    #+#             */
/*   Updated: 2022/11/22 15:51:51 by ctechy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/so_long.h"

static char	**ft_dup_map(t_prog *game)
{
	char	**res;
	char	*temp;
	int		y;

	y = 0;
	while (game->map[y])
		y++;
	res = ft_calloc(y + 1, sizeof(char *));
	if (!res)
		error_msg("Malloc failed. \n");
	y = 0;
	while (game->map[y])
	{
		temp = ft_strdup(game->map[y]);
		if (!temp)
			error_msg("Malloc failed. \n");
		res[y] = temp;
		y++;
	}
	return (res);
}

static void	ft_free_dup(char **dup)
{
	int	x;

	x = 0;
	while (dup[x])
	{
		free(dup[x]);
		x++;
	}
	free(dup);
	return ;
}

void	ft_grid(char **grid, int i, int j, t_prog *game)
{
	if (grid[j][i] == 'E')
		game->exit_check = 1;
	if (i < 0 || j < 0 || grid[j][i] == '1'
			|| grid[j][i] == 'A' || grid[j][i] == 'E')
		return ;
	grid[j][i] = 'A';
	ft_grid(grid, i, j + 1, game);
	ft_grid(grid, i, j - 1, game);
	ft_grid(grid, i + 1, j, game);
	ft_grid(grid, i - 1, j, game);
	return ;
}

void	ft_check_path(t_prog *game)
{
	char	**temp;

	game->exit_check = 0;
	temp = ft_dup_map(game);
	ft_grid(temp, game->player_x, game->player_y, game);
	if (game->exit_check == 0)
	{
		ft_putendl_fd("No Valid Path", 1);
		exit(1);
	}
	ft_free_dup(temp);
	return ;
}
