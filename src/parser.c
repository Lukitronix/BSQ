/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lukitronix <lukitronix@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 21:35:21 by lukitronix        #+#    #+#             */
/*   Updated: 2025/07/30 12:40:00 by lukitronix       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	ft_open_file(char *path, t_map **map)
{
	int fd;
	char buffer[1024];
	int bytes_read;

	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		write(2, "Error opening file\n", 19);
		return (-1);
	}
	return (fd);
}

t_map *load_map(char *path)
{	
	t_map *map;
	int fd;
	char buffer[1024];
	int bytes;

	ft_malloc(&map);
	if (!map)
		return (NULL);
	fd = ft_open_file(path, &map);
	if (fd < 0)
	{
		ft_free_map(map);
		return (NULL);
	}
	bytes = read(fd, buffer, 1024);
	if (bytes < 0)
	{
		write(2, "Error reading file\n", 19);
		close(fd);
		ft_free_map(map);
		return (NULL);
	}
	close(fd);
	return (map);
}

void ft_read_map(t_map *map, char *buffer, int size)
{
	int i ;

	i = 0;
	while (i < size)
	{
		map->raw[i] = buffer[i];
		i++;
	}
	map->raw[i] = '\0';
	i = 0;
	map->rows = 0;
	while (map->raw[i] >= '0' && map->raw[i] <= '9')
	{
		map->rows = map->rows * 10 + (map->raw[i] - '0');
		i++;
	}
	map->empty = map->raw[i];
	map->obstacle = map->raw[i + 1];
	map->full = map->raw[i + 2];
	if (map->raw[i + 3] != '\n')
		write(2, "Formato de cabecera inválido\n", 30);
}

void ft_read_columns(t_map *map)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (map->raw[i] != '\0')
	{
		if (j == 0)
			map->cols++;
		j++;
	}
	i++;
}