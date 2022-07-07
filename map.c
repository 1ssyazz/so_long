/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukri <msukri@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 14:29:59 by msukri            #+#    #+#             */
/*   Updated: 2022/07/06 16:56:23 by msukri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_map	ft_map_grid(void)
{
	t_map	map_grid;

	map_grid.collectible = 0;
	map_grid.column = 0;
	map_grid.enemy = 0;
	map_grid.exit = 0;
	map_grid.player = 0;
	map_grid.row = 0;
	return (map_grid);
}

void	ft_checkgrid(char *line, t_map *map_grid, t_error *map_err, int last)
{
	if (!map_grid->column)
		map_grid->column = ft_strlen(line) - 1;
	if (map_grid->column && ((map_grid->column != (int)ft_strlen(line) - 1 && \
			ft_strchr(line, '\n')) || \
			(map_grid->column != (int)ft_strlen(line) - 1 && \
			!ft_strchr(line, '\n'))))
		map_err->row = 1;
	if (line[0] != '1' || line[map_grid->column - 1] != '1' || \
			(ft_countchar(line, '1') != map_grid->column && last))
		map_err->borders = 1;
	map_grid->enemy += ft_countchar(line, 'G');
	map_grid->exit += ft_countchar(line, 'E');
	map_grid->player += ft_countchar(line, 'P');
	map_grid->collectible += ft_countchar(line, 'C');
	map_err->exits = map_grid->exit < 1;
	map_err->players = map_grid->player < 1;
	map_err->collectibles = map_grid->collectible < 1;
	while (line && *line)
	{
		if (!ft_strchr("01PCEG\n", *line))
			map_err->other_char = 1;
		line++;
	}
}

void	ft_readgrid(int fd, t_map *map_grid, t_error *map_err, char **map_str)
{
	char	*line;
	char	*last_line;

	line = NULL;
	last_line = NULL;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
		{
			if (!map_grid->column)
				error("Error\nMap's empty", NULL);
			else
				ft_checkgrid(last_line, map_grid, map_err, 1);
			free(last_line);
			break ;
		}
		free(last_line);
		ft_checkgrid(line, map_grid, map_err, !map_grid->row);
		last_line = ft_substr(line, 0, ft_strlen(line));
		*map_str = ft_matrixstr(*map_str, line);
		map_grid->row++;
	}
}

char	**map_check(int fd, t_map *map_grid)
{
	t_error	map_error;
	char	*map_str;
	char	**map;

	*map_grid = ft_map_grid();
	map_error = ft_init_map_error();
	map_str = NULL;
	ft_readgrid(fd, map_grid, &map_error, &map_str);
	ft_map_error(&map_error, &map_str);
	map = ft_split(map_str, '\n');
	free(map_str);
	if (!map)
		error("Error\nMalloc error", NULL);
	return (map);
}

void	update_map(t_game *g, int x, int y)
{
	if (g->map[y][x] == '1')
		mlx_put_image_to_window(g->mlx, g->mlx_win, g->sprites.wall, \
			x * SIZE, y * SIZE);
	if (g->map[y][x] == 'E')
		mlx_put_image_to_window(g->mlx, g->mlx_win, g->sprites.exit, \
			x * SIZE, y * SIZE);
	if (g->map[y][x] == 'C')
		mlx_put_image_to_window(g->mlx, g->mlx_win, g->sprites.mosquito, \
			x * SIZE, y * SIZE);
	if (g->map[y][x] == '0')
		mlx_put_image_to_window(g->mlx, g->mlx_win, g->sprites.black, \
			x * SIZE, y * SIZE);
}
