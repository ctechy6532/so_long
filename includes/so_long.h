/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctechy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 13:29:29 by ctechy            #+#    #+#             */
/*   Updated: 2022/11/08 13:29:31 by ctechy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../printf/ft_printf.h"
# include <mlx.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct s_image
{
	void	*player;
	void	*exit;
	void	*exit_p;
	void	*coin;
	void	*wall;
	void	*grass;
	int		height;
	int		width;
}				t_image;

typedef struct s_prog
{
	t_image	img;
	void	*mlx_ptr;
	void	*win;
	char	**map;
	int		x_map;
	int		y_map;
	int		player_x;
	int		player_y;
	int		exit_x;
	int		exit_y;
	int		height;
	int		coin_nb;
	int		move;
	int		exit_check;
	int		finish;
	int		p_count;
	int		exit_count;
}				t_prog;

void	do_check(t_prog *game, char *str);
void	check_ext(char *str);
void	error_map(char *mess, t_prog *game);
void	free_map(t_prog *game);
void	player_pos(t_prog *game);
void	coin_nb(t_prog *game);
void	count_make(t_prog *game);
void	exit_pos(t_prog *game);
void	ft_check_path(t_prog *game);
void	ft_grid(char **grid, int i, int j, t_prog *game);
int		free_img(t_prog *game);
void	error_free(char *mess, char *str);
void	error_msg(char *mess);
void	img_init(t_prog *game);
void	map_init(char *str, t_prog *game);
int		img_put(t_prog *game);
int		key_hook(int keycode, t_prog *game);
void	check_param(t_prog *game);

#endif
