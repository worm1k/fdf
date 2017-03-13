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

static void		transform_origin_point(t_point *point, t_data *data)
{
	// point->x = point->x + data->win_x / 2 - ((data->cols - 1) * data->step) / 2;
	// point->y = point->y + data->win_y / 2 - ((data->rows - 1) * data->step) / 2;
//	printf("x = %f - %f \n", point->x, (data->cols - 1 ) / 2.0);
	point->x = point->x - (data->cols - 1 ) / 2;
	point->y = point->y - (data->rows - 1 ) / 2;
}

static void		rotate_z_point(t_point *point, double rad)
{
	float		x;

	x = point->x * cos(rad) + point->y * sin(rad);
	point->y = -x * sin(rad) + point->y * cos(rad);
	point->x = x;
}

static void		rotate_x_point(t_point *point, double rad)
{
	float		y;

	y = point->y * cos(rad) + point->z * sin(rad);
	point->z = -1 * point->y * sin(rad) + point->z * cos(rad);
	point->y = y;
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
			//printf("x{%d} == %f\n", x, data->point[y][x].x);
			transform_origin_point(&data->point[y][x], data);
			data->point[y][x].z *= (data->step / 50.0);
			rotate_x_point(&data->point[y][x], -0.3);
			rotate_z_point(&data->point[y][x], 0.4);
			data->point[y][x].x0 = data->point[y][x].x;
			data->point[y][x].y0 = data->point[y][x].y;

			// printf("(%d,%d):[%4.2f][%4.2f]\n", y, x, data->point[y][x].y, data->point[y][x].x);
			x++;
		}
		// printf("\n");
		y++;
	}
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
/*
	p1.x = data->point[y][x].x * data->step + data->win_x / 2.0;
	p1.y = data->point[y][x].y * data->step + data->win_y / 2.0;
	p2.x = data->point[y][x - 1].x * data->step + data->win_x / 2.0;
	p2.y = data->point[y][x - 1].x * data->step + data->win_y / 2.0;
	dda_line(p1.x, p1.y, p2.x, p2.y, data);
	dda_line(p1.x, p1.y, p2.x, p2.y, data);
*/