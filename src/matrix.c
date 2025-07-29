/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulasanz <paulasanz@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 19:25:54 by paulasanz         #+#    #+#             */
/*   Updated: 2025/07/29 19:31:51 by paulasanz        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	skip_header(char *raw)
{
	int	i;

	i = 0;
	while (raw[i] && raw[i] != '\n')
		i++;
	if (raw[i] == '\n')
		i++;
	return (i);
}

int	fill_grid(char **grid, char *raw, int start, t_map *map)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = start;
	while (i < map->rows)
	{
		grid[i] = malloc(sizeof(char) * (map->cols + 1));
		if (!grid[i])
			return (0);
		j = 0;
		while (j < map->cols && raw[k] != '\n' && raw[k])
		{
			grid[i][j] = raw[k];
			j++;
			k++;
		}
		grid[i][j] = '\0';
		if (raw[k] == '\n')
			k++;
		i++;
	}
	return (1);
}

char	**create_grid(t_map *map)
{
	char	**grid;
	int		start;

	start = skip_header(map->raw);
	grid = malloc(sizeof(char *) * map->rows);
	if (!grid)
		return (NULL);
	if (!fill_grid(grid, map->raw, start, map))
		return (NULL);
	return (grid);
}

