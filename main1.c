/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukri <msukri@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 14:13:41 by msukri            #+#    #+#             */
/*   Updated: 2022/06/23 15:14:18 by msukri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	int		fd;
	char	**map;
	t_map	map_grid;

	fd = map_file_checker(argc, argv);
	if (!fd)
		return (NULL);
	map = map_check(fd, &map_grid);
	return (0);
}
