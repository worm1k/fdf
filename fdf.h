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

typedef struct		s_lst
{
	struct s_lst	*next;
	char			*buf;
	int				fd;
}					t_lst;
int					get_next_line(const int fd, char **line);

typedef struct		s_point
{
	int				color;
	unsigned int	z;
}					t_point;

typedef struct		s_data
{
	t_point			**point;
	void			*mlx;
	void			*win;
	int				rows;
	int				cols;
	int				x;
	int				y;
	void			*img;
	char			*str;
	int				bits;
	int				size;
	int				end;
}					t_data;

t_data				*read_data(const char *path);
void				print_error(int err, int row);
int					isvalid(char **split, int *rows);
int					fd_atoi(char **nptr);
int					fd_htoi(char **nptr);
void				print_struct(t_data *data);

#endif
