/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lukitronix <lukitronix@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 21:35:21 by lukitronix        #+#    #+#             */
/*   Updated: 2025/07/28 22:27:22 by lukitronix       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#define MAX_HEADER 256
#define MAX_MAP_SIZE 10000

int get_map_size(char *str)
{
    int i = 0;
    while (str[i] != '\0')
        i++;
    return i;
}

int count_columns(char *map_str, int nb_rows)
{
    (void)nb_rows; // evitar warning parámetro no usado
    int i = 0;
    int cols = 0;
    while (map_str[i] != '\n' && map_str[i] != '\0')
    {
        cols++;
        i++;
    }
    return cols;
}

t_map *load_map_from_file(char *path)
{
    int fd;
    int i;
    char header[MAX_HEADER];
    t_map *map = malloc(sizeof(t_map));
    if (!map)
        return NULL;

    fd = open(path, O_RDONLY);
    if (fd < 0)
    {
        free(map);
        return NULL;
    }

    i = 0;
    ssize_t bytes_read;
    while (i < MAX_HEADER - 1 && (bytes_read = read(fd, &header[i], 1)) > 0 && header[i] != '\n')
        i++;
    if (bytes_read <= 0)
    {
        free(map);
        close(fd);
        return NULL;
    }
    header[i] = '\0';

    if (!parse_header(header, map))
    {
        free(map);
        close(fd);
        return NULL;
    }

    map->raw = malloc(sizeof(char) * (MAX_MAP_SIZE + 1));
    if (!map->raw)
    {
        free(map);
        close(fd);
        return NULL;
    }

    i = 0;
    while (i < MAX_MAP_SIZE && (bytes_read = read(fd, &map->raw[i], 1)) > 0)
        i++;
    if (bytes_read < 0)
    {
        free(map->raw);
        free(map);
        close(fd);
        return NULL;
    }
    map->raw[i] = '\0';

    map->cols = count_columns(map->raw, map->nb_rows);

    close(fd);
    return map;
}

t_map *load_map_from_stdin(void)
{
    char header[MAX_HEADER];
    int i = 0;
    ssize_t bytes_read;
    t_map *map = malloc(sizeof(t_map));
    if (!map)
        return NULL;

    while (i < MAX_HEADER - 1 && (bytes_read = read(0, &header[i], 1)) > 0 && header[i] != '\n')
        i++;
    if (bytes_read <= 0)
    {
        free(map);
        return NULL;
    }
    header[i] = '\0';

    if (!parse_header(header, map))
    {
        free(map);
        return NULL;
    }

    map->raw = malloc(sizeof(char) * (MAX_MAP_SIZE + 1));
    if (!map->raw)
    {
        free(map);
        return NULL;
    }

    i = 0;
    while (i < MAX_MAP_SIZE && (bytes_read = read(0, &map->raw[i], 1)) > 0)
        i++;
    if (bytes_read < 0)
    {
        free(map->raw);
        free(map);
        return NULL;
    }
    map->raw[i] = '\0';

    map->cols = count_columns(map->raw, map->nb_rows);

    return map;
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

    map->nb_rows = atoi(nb_line_str);
    map->empty = header[i];
    map->obstacle = header[i + 1];
    map->full = header[i + 2];

    if (map->empty == map->obstacle || map->empty == map->full || map->obstacle == map->full)
        return 0;
    if (map->nb_rows <= 0 || !map->empty || !map->obstacle || !map->full)
        return 0;

    return 1;
}