#ifndef BSQ_H
#define BSQ_H
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

typedef struct s_map
{
    char *raw;
    int nb_rows;
    int cols;
    char empty;
    char obstacle;
    char full;
} t_map;

typedef struct s_square
{
    int size;
    int row;
    int col;
} t_square;

t_square find_biggest_square(t_map *map, int **matrix);
int parse_header(char *header, t_map *map);
t_map *load_map_from_file(const char *filename);
int min(int a, int b, int c);
void fill_square(t_map *map, t_square sq);
t_map *read_map(const char *filename);
int **create_matrix(t_map *map);
void print_map(t_map *map);

#endif