/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abykov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 19:44:03 by abykov            #+#    #+#             */
/*   Updated: 2017/01/16 19:44:04 by abykov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define BUFF_SIZE 256
# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <string.h>
# include <stdio.h>
# include "libft/libft.h"
# include <math.h>

int					get_next_line(const int fd, char **line);
typedef struct		s_lst
{
	struct s_lst	*next;
	char			*buf;
	int				fd;
}					t_lst;

typedef struct		s_data
{
	int				color;
	unsigned int	z;
}					t_data;
t_data				**read_data(const char *path);
void				print_error(int err, int row);
int					isvalid(char **split, int *rows);

#endif
