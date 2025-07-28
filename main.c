/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lukitronix <lukitronix@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 22:29:14 by lukitronix        #+#    #+#             */
/*   Updated: 2025/07/28 22:32:20 by lukitronix       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>
#include <stdlib.h>
#include "bsq.h"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <map_file>\n", argv[0]);
        return 1;
    }

    t_map *map = load_map_from_file(argv[1]);
    if (!map)
    {
        fprintf(stderr, "Error reading map file\n");
        return 1;
    }

    int **matrix = create_matrix(map);
    if (!matrix)
    {
        fprintf(stderr, "Error creating matrix\n");
        free(map->raw);
        free(map);
        return 1;
    }

    t_square sq = find_biggest_square(map, matrix);
    fill_square(map, sq);
    print_map(map);

    for (int i = 0; i < map->nb_rows; i++)
        free(matrix[i]);
    free(matrix);
    free(map->raw);
    free(map);

    return 0;
}