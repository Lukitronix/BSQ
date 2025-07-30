/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_biggest_square.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulasanz <paulasanz@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 19:35:47 by paulasanz         #+#    #+#             */
/*   Updated: 2025/07/30 16:36:38 by paulasanz        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	min(int a, int b, int c)
{
	if (a <= b && a <= c)
		return (a);
	if (b <= a && b <= c)
		return (b);
	return (c);
}

void	update_square(int value, int y, int x, t_square *sq)
{
	if (value > sq->size)
	{
		sq->size = value;
		sq->row = y;
		sq->col = x;
	}
}

void	fill_row(t_map *map, char **grid, int **aux, int y, t_square *sq)
{
	int	x;

	x = 0;
	while (x < map->cols)
	{
		if (grid[y][x] == map->obstacle)
			aux[y][x] = 0;
		else if (y == 0 || x == 0)
			aux[y][x] = 1;
		else
			aux[y][x] = 1 + min(aux[y - 1][x], aux[y][x - 1], aux[y - 1][x - 1]);
		update_square(aux[y][x], y, x, sq);
		x++;
	}
}

int	**build_matrix(t_map *map, char **grid, t_square *sq)
{
	int	**aux;
	int	y;

	aux = malloc(sizeof(int *) * map->rows);
	if (!aux)
		return (NULL);
	y = 0;
	while (y < map->rows)
	{
		aux[y] = malloc(sizeof(int) * map->cols);
		if (!aux[y])
			return (NULL);
		fill_row(map, grid, aux, y, sq);
		y++;
	}
	return (aux);
}

t_square	find_biggest_square(t_map *map, char **grid)
{
	t_square	sq;
	int			**aux;
	int			y;

	sq.size = 0;
	sq.row = 0;
	sq.col = 0;
	aux = build_matrix(map, grid, &sq);
	if (!aux)
		return (sq);
	y = 0;
	while (y < map->rows)
	{
		free(aux[y]);
		y++;
	}
	free(aux);
	return (sq);
}
