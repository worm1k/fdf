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
/*
static void		transform_origin_point(t_point *point, t_data *data)
{
	point->x = point->x - (data->cols - 1 ) / 2;
	point->y = point->y - (data->rows - 1 ) / 2;
}

void			compute_coords(t_data *data)
{
	int			y;
	int			x;

	y = 0;
	while (y < data->rows)
	{
		x = 0;
		while (x < data->cols)
		{
			transform_origin_point(&data->point[y][x], data);
			data->point[y][x].x0 = data->point[y][x].x;
			data->point[y][x].y0 = data->point[y][x].y;
			data->point[y][x].z0 = data->point[y][x].z;
			x++;
		}
		y++;
	}
}
*/
void		redraw(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img);
	data->img = mlx_new_image(data->mlx, data->win_x, data->win_y);
	data->str = mlx_get_data_addr(data->img, &data->bits, &data->size, &data->end);
	draw(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}

void			draw(t_data *data)
{
	int			y;
	int			x;

	y = 0;
	while (y < data->rows - 1)
	{
		x = data->cols - 1;
		while (x > 0)
		{
			dda_line(data->point[y][x].x, data->point[y][x].y, data->point[y][x - 1].x, data->point[y][x - 1].y, data);
			dda_line(data->point[y][x].x, data->point[y][x].y, data->point[y + 1][x].x, data->point[y + 1][x].y, data);
			x--;
		}
		y++;
	}
}