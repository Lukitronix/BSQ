#ifndef BSQ_H
# define BSQ_H

# define MAX_HEADER 64
# define MAX_MAP_SIZE 4096

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

typedef struct s_map {
	char	*raw;
	int		nb_rows;
	int		cols;
	char	empty;
	char	obstacle;
	char	full;
} t_map;

t_map	*load_map_from_file(char *path);
t_map	*load_map_from_stdin(void);
int		parse_header(char *header, t_map *map);
int		get_map_size(char *str);
int		count_columns(char *map_str);
int		ft_atoi(char *str);

#endif