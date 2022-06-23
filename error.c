/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukri <msukri@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 13:18:14 by msukri            #+#    #+#             */
/*   Updated: 2022/06/22 15:02:40 by msukri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	error(char *message)
{
	ft_putstr_fd(message, 1);
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

int	map_file_checker(int argc, char **argv)
{
	int	fd;

	if (argc == 1)
		return (error("Error\nMap not found!\n"));
	if (argc > 2)
		return (error("Error\nOnly 1 map file required!\n"));
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		error("Error\nFile not found!\n");
	if (ft_strrncmp(argv[1], ".ber", 4))
		error("Error\nInvalid file type, use .ber!");
	return (fd);
}
