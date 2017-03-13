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
	unsigned		color;
	float			z;
	float			x;
	float			y;
	float			x0;
	float			y0;
	float			z0;
}					t_point;

typedef struct		s_data
{
	t_point			**point;
	void			*mlx;
	void			*win;
	int				rows;
	int				cols;
	float			step;
	int				win_x;
	int				win_y;
	void			*img;
	char			*str;
	int				bits;
	int				size;
	int				end;
}					t_data;

int 				ft_max(int a, int b);
t_data				*read_data(const char *path);
void				print_error(int err, int row);
int					isvalid(char **split, int *rows);
void				dda_line(float x1, float y1, float x2, float y2, t_data *data);
int					fd_atoi(char **nptr);
int					fd_htoi(char **nptr);
void				print_struct(t_data *data);
void				wolf(void *mlx, void *win);
void				idinahuipidor(void *mlx, void *win);
void				compute_coords(t_data *data);
void				draw(t_data *data);
void				redraw(t_data *data);
void				zoom(t_data *data, float scale);
void				set_default(t_data *data);
void				move_y(t_data *data, float dy);
void				move_x(t_data *data, float dx);
void				rotate_x(t_data *data, double rad);
void				rotate_z(t_data *data, double rad);
void				depth(t_data *data, float alpha);

#endif
