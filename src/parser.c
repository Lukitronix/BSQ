/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulasanz <paulasanz@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 21:35:21 by lukitronix        #+#    #+#             */
/*   Updated: 2025/07/30 16:43:08 by paulasanz        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	ft_open_file(char *path)
{
	int fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		write(2, "Error opening file\n", 19);
		// ft_free_map(fd);
		return (-1);
	}
	return (fd);
}

void ft_read_columns(t_map *map)
{
	int i = 0;
	int j = 0;

	while (map->raw[i] != '\n' && map->raw[i] != '\0')
		i++;
	i++;
	while (map->raw[i + j] != '\n' && map->raw[i + j] != '\0')
		j++;
	map->cols = j;
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
	ft_read_columns(map);
	map->empty = map->raw[i];
	map->obstacle = map->raw[i + 1];
	map->full = map->raw[i + 2];
	if (map->raw[i + 3] != '\n')
		write(2, "Formato de cabecera inválido\n", 30);
	
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
	fd = ft_open_file(path);
	bytes = read(fd, buffer, 1024);
	if (bytes < 0)
	{
		write(2, "Error reading file\n", 19);
		close(fd);
		ft_free_map(map);
		return (NULL);
	}
	close(fd);
	ft_read_map(map, buffer, bytes);
	return (map);
}