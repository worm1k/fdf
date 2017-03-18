/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abykov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 17:19:05 by abykov            #+#    #+#             */
/*   Updated: 2017/03/10 17:19:05 by abykov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_red(t_data *data, int step)
{
	int		x;
	int		y;
	t_point	*p;

	y = 0;
	while (y < data->rows)
	{
		x = 0;
		while (x < data->cols)
		{
			p = &data->point[y][x];
			p->red += step;
			p->color = 0;
			p->color += p->alpha * 256 * 256 * 256;
			p->color += p->red * 256 * 256;
			p->color += p->green * 256;
			p->color += p->blue;
			x++;
		}
		y++;
	}
	redraw(data);
}

void		ft_green(t_data *data, int step)
{
	int		x;
	int		y;
	t_point	*p;

	y = 0;
	while (y < data->rows)
	{
		x = 0;
		while (x < data->cols)
		{
			p = &data->point[y][x];
			p->green += step;
			p->color = 0;
			p->color += p->alpha * 256 * 256 * 256;
			p->color += p->red * 256 * 256;
			p->color += p->green * 256;
			p->color += p->blue;
			x++;
		}
		y++;
	}
	redraw(data);
}

void		ft_blue(t_data *data, int step)
{
	int		x;
	int		y;
	t_point	*p;

	y = 0;
	while (y < data->rows)
	{
		x = 0;
		while (x < data->cols)
		{
			p = &data->point[y][x];
			p->blue += step;
			p->color = 0;
			p->color += p->alpha * 256 * 256 * 256;
			p->color += p->red * 256 * 256;
			p->color += p->green * 256;
			p->color += p->blue;
			x++;
		}
		y++;
	}
	redraw(data);
}
