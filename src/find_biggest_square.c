/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_biggest_square.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulasanz <paulasanz@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 19:35:47 by paulasanz         #+#    #+#             */
/*   Updated: 2025/07/29 19:42:44 by paulasanz        ###   ########.fr       */
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

void	fill_dp_row(t_map *map, char **grid, int **dp, int y, t_square *sq)
{
	int	x;

	x = 0;
	while (x < map->cols)
	{
		if (grid[y][x] == map->obstacle)
			dp[y][x] = 0;
		else if (y == 0 || x == 0)
			dp[y][x] = 1;
		else
			dp[y][x] = 1 + min(dp[y - 1][x], dp[y][x - 1], dp[y - 1][x - 1]);
		update_square(dp[y][x], y, x, sq);
		x++;
	}
}

int	**build_dp_matrix(t_map *map, char **grid, t_square *sq)
{
	int	**dp;
	int	y;

	dp = malloc(sizeof(int *) * map->rows);
	if (!dp)
		return (NULL);
	y = 0;
	while (y < map->rows)
	{
		dp[y] = malloc(sizeof(int) * map->cols);
		if (!dp[y])
			return (NULL);
		fill_dp_row(map, grid, dp, y, sq);
		y++;
	}
	return (dp);
}

t_square	find_biggest_square(t_map *map, char **grid)
{
	t_square	sq;
	int			**dp;
	int			y;

	sq.size = 0;
	sq.row = 0;
	sq.col = 0;
	dp = build_dp_matrix(map, grid, &sq);
	if (!dp)
		return (sq);
	y = 0;
	while (y < map->rows)
	{
		free(dp[y]);
		y++;
	}
	free(dp);
	return (sq);
}
