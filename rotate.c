/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abykov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 19:44:03 by abykov            #+#    #+#             */
/*   Updated: 2017/01/16 19:44:04 by abykov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		rotate_z(t_data *data, double rad)
{
	int		x;
	int		y;

	float	temp;
	printf("ROTZ[%+2.1f]\n", rad);
	y = 0;
	while (y < data->rows)
	{
		x = 0;
		while (x < data->cols)
		{
			temp = data->point[y][x].x * cos(rad) + data->point[y][x].y * sin(rad);
			data->point[y][x].y = -temp * sin(rad) + data->point[y][x].y * cos(rad);
			data->point[y][x].x = temp;
			x++;
		}
		y++;
	}
	redraw(data);
}

void		rotate_x(t_data *data, double rad)
{
	int		x;
	int		y;

	float	temp;
	printf("ROTX[%+2.1f]\n", rad);
	y = 0;
	while (y < data->rows)
	{
		x = 0;
		while (x < data->cols)
		{
			temp = data->point[y][x].y * cos(rad) + data->point[y][x].z * sin(rad);
			data->point[y][x].z = -1 * data->point[y][x].y * sin(rad) + data->point[y][x].z * cos(rad);
			data->point[y][x].y = temp;
			x++;
		}
		y++;
	}
	redraw(data);
}

void		depth(t_data *data, float alpha)
{
	int		x;
	int		y;

	printf("Z[%2.1f]\n", alpha);
	y = 0;
	while (y < data->rows)
	{
		x = 0;
		while (x < data->cols)
		{
			data->point[y][x].z *= alpha;
			x++;
		}
		y++;
	}
	redraw(data);
}