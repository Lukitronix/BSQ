/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmunoz <lucmunoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 21:35:21 by lukitronix        #+#    #+#             */
/*   Updated: 2025/07/30 18:17:51 by lucmunoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	ft_open_file(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		write(2, "Error opening file\n", 19);
		return (-1);
	}
	return (fd);
}

void	ft_read_columns(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map->raw[i] != '\n' && map->raw[i] != '\0')
		i++;
	i++;
	while (map->raw[i + j] != '\n' && map->raw[i + j] != '\0')
		j++;
	map->cols = j;
}

int	ft_parse_header(t_map *map, int i)
{
	int	j;

	map->full = map->raw[i - 1];
	map->obstacle = map->raw[i - 2];
	map->empty = map->raw[i - 3];
	map->rows = 0;
	j = 0;
	while (j < i - 3 && map->raw[j] >= '0' && map->raw[j] <= '9')
		map->rows = map->rows * 10 + (map->raw[j++] - '0');
	if (j != i - 3)
		return (0);
	return (1);
}

int	ft_read_map(t_map *map, char *buffer, int size)
{
	int	i;

	i = -1;
	while (++i < size)
		map->raw[i] = buffer[i];
	map->raw[i] = '\0';
	i = 0;
	while (map->raw[i] && map->raw[i] != '\n')
		i++;
	if (i < 4 || !ft_parse_header(map, i))
		return (ft_free_map_error(map));
	ft_read_columns(map);
	return (1);
}

t_map	*load_map(char *path)
{
	t_map	*map;
	int		fd;
	char	buffer[MAX_MAP_SIZE];
	int		bytes;

	ft_malloc(&map);
	if (!map)
		return (NULL);
	fd = ft_open_file(path);
	bytes = read(fd, buffer, MAX_MAP_SIZE);
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
