/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulasanz <paulasanz@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 19:52:56 by paulasanz         #+#    #+#             */
/*   Updated: 2025/07/30 17:46:02 by lucmunoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	main(int argc, char **argv)
{
	t_map	*map;
	char	**grid;

	map = load_map(argv[1]);
	grid = create_grid(map);
	fill_square(map, grid, find_biggest_square(map, grid));
	print_grid(grid, map->rows);
	(void)argc;
	return (0);
}

// int	main(int argc, char **argv)
// {
// 	t_map *map;
// 	char **grid;
// 	int start;

// 	if (argc != 2)
// 	{
// 		write(2, "Usage: ./bsq map.txt\n", 22);
// 		return (1);
// 	}
// 	if (!map)
// 		return (1);

// 	start = skip_header(map->raw);
// 	if (start == -1)
// 	{
// 		write(2, "Invalid map header\n", 20);
// 		ft_free_map(map);
// 		return (1);
// 	}

// 	ft_read_map(map, map->raw + start, get_map_size(map->raw));
// 	ft_read_columns(map);

// 	grid = create_grid(map);
// 	if (!grid)
// 	{
// 		write(2, "Error creating grid\n", 21);
// 		ft_free_map(map);
// 		return (1);
// 	}

// 	if (fill_grid(grid, map->raw, start, map) != 0)
// 	{
// 		write(2, "Error filling grid\n", 20);
// 		ft_free_map(map);
// 		return (1);
// 	}

// 	print_grid(grid, map->rows);

// 	// Liberar memoria
// 	for (int i = 0; i < map->rows; i++)
// 		free(grid[i]);
// 	free(grid);
// 	ft_free_map(map);

// 	return (0);
// }
