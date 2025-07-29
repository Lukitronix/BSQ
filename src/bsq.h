/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lukitronix <lukitronix@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 17:23:59 by lukitronix        #+#    #+#             */
/*   Updated: 2025/07/29 18:05:57 by lukitronix       ###   ########.fr       */
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
	char	*raw;
	int		nb_rows;
	int		cols;
	char	empty;
	char	obstacle;
	char	full;
} t_map;

void	ft_stdin(void);
void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_putnbr(int nbr);
void	ft_malloc(void);

#endif