/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lukitronix <lukitronix@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 17:23:59 by lukitronix        #+#    #+#             */
/*   Updated: 2025/07/30 12:13:57 by lukitronix       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# define MAX_MAP_SIZE 4096
# define MAX_HEADER 64

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <errno.h>
# include <libgen.h>

typedef struct s_map
{
	char		*raw;
	int		rows;
	int		cols;
	char	empty;
	char	obstacle;
	char	full;
} t_map;

typedef struct s_square
{
	int		size;
	int		row;
	int		col;
}	t_square;

int	ft_open_file(char *path, t_map **map);
t_map *load_map(char *path);
void ft_read_map(t_map *map, char *buffer, int size);
void ft_read_columns(t_map *map);
void	ft_putchar(char c);
int get_map_size(char *str);
int	ft_isspace(char c);
int	ft_isdigit(char c);
int	ft_atoi(char *str);

int	skip_header(char *raw);
int	fill_grid(char **grid, char *raw, int start, t_map *map);
char	**create_grid(t_map *map);
void	fill_square(t_map *map, char **grid, t_square sq);
void	print_grid(char **grid, int rows);
void	ft_malloc(t_map **map);
void ft_free_map(t_map *map);


#endif