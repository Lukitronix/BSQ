/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lukitronix <lukitronix@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 19:52:56 by paulasanz         #+#    #+#             */
/*   Updated: 2025/07/30 12:15:47 by lukitronix       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "bsq.h"

int	main(int argc, char **argv)
{
	t_map *map;
	char **grid;
	int start;

	if (argc != 2)
	{
		write(2, "Usage: ./bsq map.txt\n", 22);
		return (1);
	}

	ft_malloc(&map);
	if (!map)
		return (1);

	if (ft_open_file(argv[1], &map) != 0)
	{
		write(2, "Error opening file\n", 20);
		return (1);
	}

	start = skip_header(map->raw);
	if (start == -1)
	{
		write(2, "Invalid map header\n", 20);
		ft_free_map(map);
		return (1);
	}

	ft_read_map(map, map->raw + start, get_map_size(map->raw));
	ft_read_columns(map);

	grid = create_grid(map);
	if (!grid)
	{
		write(2, "Error creating grid\n", 21);
		ft_free_map(map);
		return (1);
	}

	if (fill_grid(grid, map->raw, start, map) != 0)
	{
		write(2, "Error filling grid\n", 20);
		ft_free_map(map);
		return (1);
	}

	print_grid(grid, map->rows);

	// Liberar memoria
	for (int i = 0; i < map->rows; i++)
		free(grid[i]);
	free(grid);
	ft_free_map(map);

	return (0);
}