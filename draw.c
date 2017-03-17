/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abykov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 17:19:05 by abykov            #+#    #+#             */
/*   Updated: 2017/03/10 17:19:05 by abykov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static unsigned	get_color(unsigned char red, unsigned char green,
unsigned char blue, unsigned char alpha)
{
	unsigned	res;
	unsigned	temp;

	res = 0;
	res += alpha * 256 * 256 * 256;
	res += red * 256 * 256;
	res += green * 256;
	res += blue;
	return (res);
}

static void		img_pixel_put(t_data *data, int x, int y, unsigned color)
{
	size_t		i;

	x += data->win_x / 2.0;
	y += data->win_y / 2.0;
	if (x < 0 || y < 0 || data->win_x - 1 < x || data->win_y - 1 < y)
	{
		return ;
	}
	i = y * (data->size) + x * 4;
	data->str[i] = color % 256;
	data->str[i + 1] = (color / 256) % 256;
	data->str[i + 2] = (color / 256 / 256) % 256;
	data->str[i + 3] = color / 256 / 256 / 256;
}

static void		dda_line(t_data *data, t_point *p1, t_point *p2)
{
	int			var0[6];
	float		var1[16];
	unsigned	color;

	ft_xy(var1, p1, p2, data);
	ft_startend(var0, var1);
	var0[1] = ft_max(abs(var0[4] - var0[2]), abs(var0[5] - var0[3]));
	if (var0[1] == 0)
		return ;
	ft_divide(var1, p1, p2, var0[1]);
	var0[0] = 0;
	img_pixel_put(data, roundf(var1[6]), roundf(var1[7]), p1->color);
	ft_something(var1, p1);
	(var0[0])++;
	while (var0[0] < var0[1])
	{
		color = get_color(roundf(var1[12] + var1[2]), roundf(var1[13] +
			var1[3]), roundf(var1[14] + var1[4]), roundf(var1[15] + var1[5]));
		img_pixel_put(data, roundf(var1[10] + var1[0]),
			roundf(var1[11] + var1[1]), color);
		ft_inc(var1);
		(var0[0])++;
	}
	img_pixel_put(data, roundf(var1[8]), roundf(var1[9]), p2->color);
}

void			redraw(t_data *dat)
{
	mlx_destroy_image(dat->mlx, dat->img);
	dat->img = mlx_new_image(dat->mlx, dat->win_x, dat->win_y);
	dat->str = mlx_get_data_addr(dat->img, &dat->b, &dat->size, &dat->end);
	draw(dat);
	mlx_put_image_to_window(dat->mlx, dat->win, dat->img, 0, 0);
}

void			draw(t_data *data)
{
	int			y;
	int			x;

	y = 0;
	while (y < data->rows)
	{
		x = data->cols - 1;
		while (x >= 0)
		{
			if (x != 0)
				dda_line(data, &data->point[y][x], &data->point[y][x - 1]);
			if (y != data->rows - 1)
				dda_line(data, &data->point[y][x], &data->point[y + 1][x]);
			x--;
		}
		y++;
	}
}
