/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lukitronix <lukitronix@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 22:11:46 by lukitronix        #+#    #+#             */
/*   Updated: 2025/07/30 11:58:55 by lukitronix       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int **map_to_int(t_map *map)
{
	int **matrix;
	int i = 0, x, y = 0;

	matrix = malloc(sizeof(int *) * map->rows);
	if (!matrix)
		return (0);
	while (y < map->rows)
	{
		matrix[y] = malloc(sizeof(int) * map->cols);
		if (!matrix[y])
			return (0);
		x = 0;
		while (map->raw[i] != '\n')
		{
			if (map->raw[i] == map->empty)
				matrix[y][x] = 1;
			else if (map->raw[i] == map->obstacle)
				matrix[y][x] = 0;
			i++;
			x++;
		}
		i++;
		y++;
	}
	return (matrix);
}