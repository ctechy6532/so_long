/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctechy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 16:33:01 by ctechy            #+#    #+#             */
/*   Updated: 2022/11/23 16:33:02 by ctechy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/so_long.h"

static void	map_init_extra(int fd, char *line, char *full_lines, t_prog *game)
{
	game->map = ft_split(full_lines, '\n');
	if (!game->map)
		error_msg("Malloc failed.");
	game->x_map = ft_strlen(game->map[0]);
	free(line);
	free(full_lines);
	close(fd);
}

void	map_init(char *str, t_prog *game)
{
	int		fd;
	char	*line;
	char	*full_lines;

	fd = open(str, O_RDONLY);
	if (fd < 0)
		error_msg("File doesn't exist.");
	full_lines = ft_strdup("");
	line = "";
	if (!full_lines)
		error_free("Malloc failed.", full_lines);
	while (line)
	{
		line = get_next_line(fd);
		if (!line || line[0] == '\n')
			break ;
		full_lines = ft_strjoin(full_lines, line);
		if (!full_lines)
			error_free("Malloc failed.", full_lines);
		free(line);
		game->height++;
	}
	map_init_extra(fd, line, full_lines, game);
}
