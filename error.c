/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukri <msukri@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 13:18:14 by msukri            #+#    #+#             */
/*   Updated: 2022/06/30 14:19:47 by msukri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	error(char *message, char **map_str)
{
	if (map_str)
		free(*map_str);
	ft_putstr_fd(message, 1);
	ft_putchar_fd('\n', 1);
	exit(0);
	return (0);
}

t_error	ft_init_map_error(void)
{
	t_error	map_error;

	map_error.borders = 0;
	map_error.collectibles = 0;
	map_error.enemies = 0;
	map_error.exits = 0;
	map_error.other_char = 0;
	map_error.players = 0;
	map_error.row = 0;
	return (map_error);
}

int	ft_map_error(t_error *map_error, char **map_str)
{
	if (map_error->row)
		error("Error\nMap is not rectangular!", map_str);
	if (map_error->borders)
		error("Error\nMap is not restricted by wall!", map_str);
	if (map_error->other_char)
		error("Error\nMap consists of invalid char!", map_str);
	if (map_error->exits)
		error("Error\nInvalid number of exits", map_str);
	if (map_error->players)
		error("Error\nInvalid number of players", map_str);
	if (map_error->collectibles)
		error("Error\nInvalid number of collectibles", map_str);
	return (0);
}

int	map_file_checker(int argc, char **argv)
{
	int	fd;

	if (argc == 1)
		return (error(("Error\nMap not found!"), NULL));
	if (argc > 2)
		return (error("Error\nOnly 1 map file required!", NULL));
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		error("Error\nFile not found!", NULL);
	if (ft_strrncmp(argv[1], ".ber", 4))
		error("Error\nInvalid file type, use .ber!", NULL);
	return (fd);
}
