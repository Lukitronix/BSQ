/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulasanz <paulasanz@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 18:56:52 by paulasanz         #+#    #+#             */
/*   Updated: 2025/07/30 15:54:20 by paulasanz        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void ft_free_map(t_map *map)
{
	if (map)
	{
		if (map->raw)
			free(map->raw);
		free(map);
	}
}

void	ft_malloc(t_map **map)
{
	*map = malloc(sizeof(t_map));
	if (!*map)
		ft_errors();
	(*map)->raw = malloc(sizeof(char) * MAX_MAP_SIZE);
	if (!(*map)->raw)
	{
		write(2, "Error\n", 6);
		free(*map);
		*map = NULL;
	}
}