/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lukitronix <lukitronix@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 17:03:38 by lucmunoz          #+#    #+#             */
/*   Updated: 2025/07/29 17:13:15 by lukitronix       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

void ft_putnbr(int n)
{
	char c;
	if (n >= 10)
		ft_putnbr(n / 10);
	c = '0' + (n % 10);
	write(1, &c, 1);
}

int	is_valid_map(t_map *map)
{
	int	i = 0;
	int	current_cols = 0;

	if (map->nb_rows <= 0 || map->cols <= 0)
		return (0);

	while (map->raw[i])
	{
		current_cols = 0;
		while (map->raw[i] && map->raw[i] != '\n')
		{
			if (map->raw[i] != map->empty &&
				map->raw[i] != map->obstacle &&
				map->raw[i] != map->full)
				return (0);
			current_cols++;
			i++;
		}
		if (current_cols != map->cols)
			return (0);
		if (map->raw[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}

void	print_map_info(t_map *map)
{
	write(1, "Líneas: ", 9);
	ft_putnbr(map->nb_rows);
	write(1, "\nColumnas: ", 12);
	ft_putnbr(map->cols);
	write(1, "\nEmpty: ", 8);
	write(1, &map->empty, 1);
	write(1, "\nObstacle: ", 11);
	write(1, &map->obstacle, 1);
	write(1, "\nFull: ", 7);
	write(1, &map->full, 1);
	write(1, "\n", 1);
}

int	main(int argc, char **argv)
{
	int		i;
	t_map	*map;

	if (argc == 1)
	{
		map = load_map_from_stdin();
		if (!map || !is_valid_map(map))
			write(1, "map error\n", 10);
		else
			print_map_info(map);
		free(map->raw);
		free(map);
		return (0);
	}
	i = 1;
	while (i < argc)
	{
		map = load_map_from_file(argv[i]);
		if (!map || !is_valid_map(map))
			write(1, "map error\n", 10);
		else
			print_map_info(map);
		if (map)
		{
			free(map->raw);
			free(map);
		}
		i++;
		if (i < argc)
			write(1, "\n", 1);
	}
	return (0);
}