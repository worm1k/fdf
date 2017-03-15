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
			data->point[y][x].z = data->point[y][x].z0;
			x++;
		}
		y++;
	}
	redraw(data);
}




