/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctechy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 14:59:03 by ctechy            #+#    #+#             */
/*   Updated: 2022/11/22 14:59:05 by ctechy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	var_init(t_prog *game)
{
	game->y_map = 0;
	game->x_map = 0;
	game->player_x = 0;
	game->player_y = 0;
	game->height = 0;
	game->exit_x = 0;
	game->exit_y = 0;
	game->coin_nb = 0;
	game->move = 1;
	game->finish = 0;
	game->p_count = 0;
	game->exit_count = 0;
}

int	free_img(t_prog *game)
{
	free_map(game);
	mlx_destroy_image(game->mlx_ptr, game->img.coin);
	mlx_destroy_image(game->mlx_ptr, game->img.exit);
	mlx_destroy_image(game->mlx_ptr, game->img.grass);
	mlx_destroy_image(game->mlx_ptr, game->img.player);
	mlx_destroy_image(game->mlx_ptr, game->img.wall);
	mlx_destroy_window(game->mlx_ptr, game->win);
	exit(0);
}

int	main(int ac, char **argv)
{
	t_prog	game;

	if (ac != 2)
	{
		ft_putendl_fd("Invalid arguments.", 2);
		exit(1);
	}
	var_init(&game);
	map_init(argv[1], &game);
	count_make(&game);
	do_check(&game, argv[1]);
	ft_check_path(&game);
	game.mlx_ptr = mlx_init();
	game.win = mlx_new_window(game.mlx_ptr, game.x_map * 32,
			game.height * 32, "so_long");
	img_init(&game);
	mlx_loop_hook(game.mlx_ptr, img_put, &game);
	mlx_hook(game.win, 2, 1L << 0, key_hook, &game);
	mlx_hook(game.win, 17, 1L << 0, free_img, &game);
	mlx_loop(game.mlx_ptr);
}
