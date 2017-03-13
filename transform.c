/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abykov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 19:44:03 by abykov            #+#    #+#             */
/*   Updated: 2017/01/16 19:44:04 by abykov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		redraw(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img);
	data->img = mlx_new_image(data->mlx, data->win_x, data->win_y);
	data->str = mlx_get_data_addr(data->img, &data->bits, &data->size, &data->end);
	draw(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}

void		move_x(t_data *data, float dx)
{
	int		x;
	int		y;

	printf("X[%+2.1f]\n", dx);
	y = 0;
	while (y < data->rows)
	{
		x = 0;
		while (x < data->cols)
		{
			data->point[y][x].x += dx;
			x++;
		}
		y++;
	}
	redraw(data);
}

void		move_y(t_data *data, float dy)
{
	int		x;
	int		y;

	printf("Y[%+2.1f]\n", dy);
	y = 0;
	while (y < data->rows)
	{
		x = 0;
		while (x < data->cols)
		{
			data->point[y][x].y += dy;
			x++;
		}
		y++;
	}
	redraw(data);
}

void		zoom(t_data *data, float scale)
{
	int				x;
	int				y;

	printf("SCALE[%2.1f]\n", scale);
	y = 0;
	while (y < data->rows)
	{
		x = 0;
		while (x < data->cols)
		{
			data->point[y][x].x *= scale;
			data->point[y][x].y *= scale;
			x++;
		}
		y++;
	}
	redraw(data);
}

void		set_default(t_data *data)
{
	int				x;
	int				y;

	printf("DEFAULT\n");
	y = 0;
	while (y < data->rows)
	{
		x = 0;
		while (x < data->cols)
		{
			data->point[y][x].x = data->point[y][x].x0;
			data->point[y][x].y = data->point[y][x].y0;
			x++;
		}
		y++;
	}
	redraw(data);
}




