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

//	printf("%#.2x%.2x%.2x%.2x -->", alpha, red, green, blue);
	res = 0;
	res += alpha * 256 * 256 * 256;
	res += red * 256 * 256;
	res += green * 256;
	res += blue;
//	printf("COLOR[%#.8x]\n", res);
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
static void		dda_line3(t_data *data, t_point *p1, t_point *p2)
{
	int			var0[6];
	float		var1[16];
	unsigned	color;

	ft_x1x2y1y2(var1, p1, p2, data);
	var0[1] = ft_max(abs(var0[4] - var0[2]), abs(var0[5] - var0[4]));
	if (var0[1] == 0)
		return ;
	ft_divide(var1, p1, p2, var0[1]);
	var0[0] = 0;
	img_pixel_put(data, roundf(var1[6]), roundf(var1[7]), p1->color);
	ft_somesthing(var1, p1);
	(var0[0])++;
	while (var0[0] < var0[1])
	{
		color = get_color(roundf(var1[12] + var1[2]), roundf(var1[13] + var1[3]), roundf(var1[14] + var1[4]), roundf(var1[15] + var1[5]));
		img_pixel_put(data, roundf(var1[10] + var1[0]), roundf(var1[11] + var1[1]), color);
		ft_inc(var1);
		(var0[0])++;
	}
	img_pixel_put(data, roundf(var1[8]), roundf(var1[9]), p2->color);
}

static void		dda_line1(t_data *data, t_point *p1, t_point *p2)
{
	int			i, L, xstart, ystart, xend, yend;
	float		dx, dy, dr, dg, db, da, x1, x2, y1, y2, xi, yi, ri, gi, bi, ai;
	float		var1[16];
	unsigned	color;

	x1 = p1->x * data->step;
	y1 = p1->y * data->step;
	x2 = p2->x * data->step;
	y2 = p2->y * data->step;
	xstart = roundf(x1);
	ystart = roundf(y1);
	xend = roundf(x2);
	yend = roundf(y2);
	L = ft_max(abs(xend-xstart), abs(yend-ystart));
	if (L == 0)
		return ;
	dx = (x2-x1) / L;
	dy = (y2-y1) / L;
	dr = (p2->red - p1->red) / L;
	dg = (p2->green - p1->green) / L;
	db = (p2->blue - p1->blue) / L;
	da = (p2->alpha - p1->alpha) / L;
	i = 0;
	img_pixel_put(data, roundf(x1), roundf(y1), p1->color);
	xi = x1;
	yi = y1;
	ri = p1->red;
	gi = p1->green;
	bi = p1->blue;
	ai = p1->alpha;
	i++;
	while (i < L)
	{
		color = get_color(roundf(ri + dr), roundf(gi + dg), roundf(bi + db), roundf(ai + da));
		img_pixel_put(data, roundf(xi + dx), roundf(yi + dy), color);
		xi = xi + dx;
		yi = yi + dy;
		ri = ri + dr;
		gi = gi + dg;
		bi = bi + db;
		ai = ai + da;
		i++;
	}
	img_pixel_put(data, roundf(x2), roundf(y2), p2->color);
}

static void		dda_line2(t_data *data, t_point *p1, t_point *p2)
{
	int			i, L, xstart, ystart, xend, yend;
	float		dx, dy, xi, yi, x1, x2, y1, y2;

	x1 = p1->x * data->step;
	y1 = p1->y * data->step;
	x2 = p2->x * data->step;
	y2 = p2->y * data->step;
	xstart = roundf(x1);
	ystart = roundf(y1);
	xend = roundf(x2);
	yend = roundf(y2);
	L = ft_max(abs(xend-xstart), abs(yend-ystart));
	dx = (x2-x1) / L;
	dy = (y2-y1) / L;
	i = 0;
	img_pixel_put(data, roundf(x1), roundf(y1), 0xFFFFFF);
	xi = x1;
	yi = y1;
	i++;
	while (i < L)
	{
		img_pixel_put(data, roundf(xi + dx), roundf(yi + dy), 0xFFFFFF);
		xi = xi + dx;
		yi = yi + dy;
		i++;
	}
	img_pixel_put(data, roundf(x2), roundf(y2), 0xFFFFFF);
}

static void		dda_line(float x1, float y1, float x2, float y2, t_data *data)
{
	int		i, L, xstart, ystart, xend, yend;
	float	dX, dY, xi, yi;

	x1 *= data->step;
	y1 *= data->step;
	x2 *= data->step;
	y2 *= data->step;
	xstart = roundf(x1);
	ystart = roundf(y1);
	xend = roundf(x2);
	yend = roundf(y2);
	L = ft_max(abs(xend-xstart), abs(yend-ystart));
	if (L == 0)
		return ;
	dX = (x2-x1) / L;
	dY = (y2-y1) / L;
	i = 0;
	img_pixel_put(data, roundf(x1), roundf(y1), 0xffffff);
	xi = x1;
	yi = y1;
	i++;
	while (i < L)
	{
		img_pixel_put(data, roundf(xi + dX), roundf(yi + dY), 0xffffff);
		xi = xi + dX;
		yi = yi + dY;
		i++;
	}
	img_pixel_put(data, roundf(x2), roundf(y2), 0xffffff);
}

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
			dda_line3(data, &data->point[y][x], &data->point[y][x - 1]);
			dda_line3(data, &data->point[y][x], &data->point[y + 1][x]);
			// dda_line(data->point[y][x].x, data->point[y][x].y, data->point[y][x - 1].x, data->point[y][x - 1].y, data);
			// dda_line(data->point[y][x].x, data->point[y][x].y, data->point[y + 1][x].x, data->point[y + 1][x].y, data);
			x--;
		}
		y++;
	}
}
