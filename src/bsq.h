/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmunoz <lucmunoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 17:23:59 by lukitronix        #+#    #+#             */
/*   Updated: 2025/07/30 18:13:31 by lucmunoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# define MAX_MAP_SIZE 8300000
# define MAX_HEADER 64

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <errno.h>
# include <libgen.h>

typedef struct s_map
{
	char	*raw;
	int		rows;
	int		cols;
	char	empty;
	char	obstacle;
	char	full;
	char	**grid;
	int		**aux;
}	t_map;

typedef struct s_square
{
	int		size;
	int		row;
	int		col;
}	t_square;

void		ft_errors(void);
int			ft_free_map_error(t_map *map);
int			ft_strlen(char *str);
t_map		*load_map(char *path);
t_square	find_biggest_square(t_map *map, char **grid);
char		**create_grid(t_map *map);
void		fill_square(t_map *map, char **grid, t_square sq);
void		print_grid(char **grid, int rows);
void		ft_malloc(t_map **map);
void		ft_free_map(t_map *map);

#endif