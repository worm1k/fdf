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

void		rotate_z(t_data *data, float rad)
{
	int		x;
	int		y;

	float	temp_x;
	float	temp_y;
	printf("ROTZ[%+.1f]\n", rad);
	y = 0;
	while (y < data->rows)
	{
		x = 0;
		while (x < data->cols)
		{
			temp_x = data->point[y][x].x;
			temp_y = data->point[y][x].y;
			data->point[y][x].x = temp_x * cosf(rad) + temp_y * sinf(rad);
            data->point[y][x].y = temp_y * cosf(rad) - temp_x * sinf(rad);
            x++;
		}
		y++;
	}
	redraw(data);
}

void		rotate_x(t_data *data, float rad)
{
	int		x;
	int		y;

	float	temp;
	float	temp_z;
	printf("ROTX[%+.1f]\n", rad);
	y = 0;
	while (y < data->rows)
	{
		x = 0;
		while (x < data->cols)
		{
			temp = data->point[y][x].y * cosf(rad) + data->point[y][x].z * sinf(rad);
			data->point[y][x].z = data->point[y][x].z * cosf(rad) - data->point[y][x].y * sinf(rad);
			data->point[y][x].y = temp;
			x++;
		}
		y++;
	}
	redraw(data);
}

void		rotate_y(t_data *data, float rad)
{
	
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