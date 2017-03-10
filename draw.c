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

static void		rotate_z(t_point *point, double rad)
{
	int			x;

	x = point->x * cos(rad) + point->y * sin(rad);
	point->y = -x * sin(rad) + point->y * cos(rad);
	point->x = x;
}

static void		rotate_x(t_point *point, double rad)
{
	int			y;

	y = point->y * cos(rad) + point->z * sin(rad);
	point->z = -1 * point->y * sin(rad) + point->z * cos(rad);
	point->y = y;
}

static void		compute_coords(t_data *data)
{
	int			y;
	int			x;

	y = 0;
	while (y < data->rows)
	{
		x = 0;
		while (x < data->cols)
		{
			data->point[y][x].y = data->step * y;
			data->point[y][x].x = data->step * x;
			data->point[y][x].z = (data->step / 10) * data->point[y][x].z;
			rotate_x(&data->point[y][x], (M_PI / 3));
			//rotate_z(&data->point[y][x], M_PI_4);
			printf("(%d,%d):[%d][%d]\n", y, x, data->point[y][x].y, data->point[y][x].x);
			x++;
		}
		y++;
	}

}

void			draw(t_data *data)
{
	int			y;
	int			x;

	compute_coords(data);
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
