/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_matrix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulasanz <paulasanz@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 19:51:53 by paulasanz         #+#    #+#             */
/*   Updated: 2025/07/29 19:52:39 by paulasanz        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	fill_square(t_map *map, char **grid, t_square sq)
{
	int	y;
	int	x;
	int	start_y;
	int	start_x;

	start_y = sq.row - sq.size + 1;
	start_x = sq.col - sq.size + 1;
	y = start_y;
	while (y <= sq.row)
	{
		x = start_x;
		while (x <= sq.col)
		{
			grid[y][x] = map->full;
			x++;
		}
		y++;
	}
}

void	print_grid(char **grid, int rows)
{
	int	i;

	i = 0;
	while (i < rows)
	{
		write(1, grid[i], ft_strlen(grid[i]));
		write(1, "\n", 1);
		i++;
	}
}
