/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lukitronix <lukitronix@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 21:35:21 by lukitronix        #+#    #+#             */
/*   Updated: 2025/07/29 18:20:38 by lukitronix       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	ft_malloc(t_map *map)
{
	map = malloc(sizeof(t_map));
	map->raw = malloc(sizeof(char) * MAX_MAP_SIZE);
	if (!map)
	{
		write(2, "Error\n", 7);
		return (1);
	}
}

int	ft_open_file(char *path, t_map *map)
{
	int fd;
	char buffer[1024];
	int bytes_read;

	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		write(2, "Error opening file\n", 19);
		return;
	}
	ft_malloc(map);
	return (fd);
}

void ft_free_map(t_map *map)
{
	if (map)
	{
		if (map->raw)
			free(map->raw);
		free(map);
	}
}

t_map *load_map(char *path)
{	
	t_map *map;
	int fd;
	char buffer[1024];
	int bytes;

	(void)map;
	fd = ft_open_file(path, map);
	if (fd < 0)
		return (0);
	bytes = read(fd, buffer, 1024);
	if (bytes < 0)
	{
		write(2, "Error reading file\n", 19);
		close(fd);
		return (0);
	}
	
}

t_map *load_map_from_stdin(void)
{
	char header[MAX_HEADER];
	int i = 0;
	t_map *map = malloc(sizeof(t_map));
	if (!map)
		return (0);
	while (read(0, &header[i], 1) > 0 && header[i] != '\n')
		i++;
	header[i] = '\0';
	if (!parse_header(header, map))
		return (0);
	map->raw = malloc(sizeof(char) * MAX_MAP_SIZE);
	if (!map->raw)
		return (0);
	i = 0;
	while (read(0, &map->raw[i], 1) > 0 && i < MAX_MAP_SIZE)
		i++;
	map->raw[i] = '\0';
	map->cols = count_columns(map->raw);
	return (map);
}

int parse_header(char *header, t_map *map)
{
	int i = 0;
	char nb_line_str[12];
	int j = 0;

	while (header[i] >= '0' && header[i] <= '9')
	{
		nb_line_str[j] = header[i];
		i++;
		j++;
	}
	nb_line_str[j] = '\0';
	map->nb_rows = ft_atoi(nb_line_str);
	map->empty = header[i];
	map->obstacle = header[i + 1];
	map->full = header[i + 2];
	if (map->empty == map->obstacle || map->empty == map->full || map->obstacle == map->full)
		return (0);
	return (1);
}