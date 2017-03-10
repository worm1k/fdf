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

int 		ft_max(int a, int b)
{
	return (a > b) ? (a) : (b);
}

void		img_pixel_put(t_data *data, int x, int y, int color)
{
	size_t		i;

	if (x < 0 || y < 0)
		return ;
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

	printf("JOPA\n");
	xstart = roundf(x1);
	ystart = roundf(y1);
	xend = roundf(x2);
	yend = roundf(y2);
	L = ft_max(abs(xend-xstart), abs(yend-ystart));
	dX = (x2-x1) / L;
	dY = (y2-y1) / L;
	i = 0;
	printf("JOPA2\n");
	img_pixel_put(data, roundf(x1), roundf(y1), 0xffffff);
	xi = x1;
	yi = y1;
	i++;
	printf("JOPA3\n");
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
	printf("img:[%d]x[%d]\n", data->x_max - data->x_0, data->y_max - data->y_0);
	data->win = mlx_new_window(data->mlx, data->win_x, data->win_y, "HUI_PIZDA");
	data->img = mlx_new_image(data->mlx, data->x_max - data->x_0, data->y_max - data->y_0);
	data->str = mlx_get_data_addr(data->img, &data->bits, &data->size, &data->end);

	printf("[%d][%d][%d]\n", data->bits, data->size, data->end);
	/*
	dda_line(0, 0, 800, 0, &data);
	dda_line(800, 0, 800, 800, &data);
	dda_line(800, 800, 0, 800, &data);
	dda_line(0, 800, 0, 0, &data);
	*/
	printf("[%d]\n", data->step);
	draw(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 100, 100);
	mlx_loop(data->mlx);
	return (0);
}



















