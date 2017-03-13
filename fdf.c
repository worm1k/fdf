/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abykov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 19:44:03 by abykov            #+#    #+#             */
/*   Updated: 2017/01/16 19:44:04 by abykov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <locale.h>

void		select_func_2(int keycode, t_data *data)
{

}

int			select_func(int keycode, t_data *data)
{
	if (keycode == 126)
		move_y(data, -0.5);
	else if (keycode == 125)
		move_y(data, 0.5);
	else if (keycode == 123)
		move_x(data, -1);
	else if (keycode == 124)
		move_x(data, 1);
	else if (keycode == 69)
		zoom(data, 1.1);
	else if (keycode == 78)
		zoom(data, 0.9);
	else if (keycode == 82)
		set_default(data);
	else if (keycode == 67)
		depth(data, 1.1);
	else if (keycode == 75)
		depth(data, 0.9);
	else if (keycode == 87)
		rotate_x(data, -0.1);
	else if (keycode == 84)
		rotate_x(data, 0.1);
	else if (keycode == 83)
		rotate_z(data, 0.1);
	else if (keycode == 85)
		rotate_z(data, -0.1);
	return (0);
}

int 		ft_max(int a, int b)
{
	return (a > b) ? (a) : (b);
}

void		img_pixel_put(t_data *data, int x, int y, int color)
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

void		dda_line(float x1, float y1, float x2, float y2, t_data *data)
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


int			main(int argc, char **argv)
{
	t_data	*data;

	if (argc == 2)
		data = read_data(argv[1]);

	data->mlx = mlx_init();
	printf("win:[%d]x[%d]\n", data->win_x, data->win_y);
	printf("img:[%d]x[%d]\n", data->win_x, data->win_y);
	data->win = mlx_new_window(data->mlx, data->win_x, data->win_y, "HUI_PIZDA");
	data->img = mlx_new_image(data->mlx, data->win_x, data->win_y);
	data->str = mlx_get_data_addr(data->img, &data->bits, &data->size, &data->end);

	printf("[%d][%d][%d]\n", data->bits, data->size, data->end);
	printf("[%4.2f]\n", data->step);
	compute_coords(data);
	draw(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);

	mlx_hook(data->win, 2, 5, select_func, data);
	mlx_loop(data->mlx);
	return (0);
}



















