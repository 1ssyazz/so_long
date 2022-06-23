/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukri <msukri@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 14:29:59 by msukri            #+#    #+#             */
/*   Updated: 2022/06/23 15:18:12 by msukri           ###   ########.fr       */
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

void	ft_read_grid(int fd, t_map *map_grid, t_error *map_err, char **map_str)
{
	char	*line;
	char	*last_line;

	line = NULL;
	last_line = NULL;
	while (1)
	{
		line = 
	}
}

char	**map_check(int fd, t_map *map_grid)
{
	t_error	map_error;
	char	*map_str;

	*map_grid = ft_map_grid();
	map_error = ft_init_map_error();
	map_str = NULL;
	ft_read_grid(fd, map_grid, &map_error, &map_str);
}
