/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctechy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 15:50:19 by ctechy            #+#    #+#             */
/*   Updated: 2022/11/22 15:50:21 by ctechy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	error_msg(char *mess)
{
	ft_putendl_fd(mess, 1);
	exit(1);
}

void	free_map(t_prog *game)
{
	int	i;

	i = 0;
	while (game->map[i])
	{
		free(game->map[i]);
		i++;
	}
	free(game->map);
}

void	error_free(char *mess, char *str)
{
	free(str);
	ft_putendl_fd(mess, 1);
	exit(1);
}

void	error_map(char *mess, t_prog *game)
{
	free_map(game);
	ft_putendl_fd(mess, 1);
	exit(1);
}
