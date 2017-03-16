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

void		close_fdf(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img);
	mlx_destroy_window(data->mlx, data->win);
	exit(0);
}

void		select_func_2(int keycode, t_data *data)
{
	if (keycode == 83)
		rotate_z(data, 0.05);
	else if (keycode == 85)
		rotate_z(data, -0.05);
	else if (keycode == 86)
		rotate_y(data, -0.05);
	else if (keycode == 88)
		rotate_y(data, 0.05);
	else if (keycode == 53)
		close_fdf(data);
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
		zoom(data, 10.0 / 11.0);
	else if (keycode == 82)
		set_default(data);
	else if (keycode == 67)
		depth(data, 1.1);
	else if (keycode == 75)
		depth(data, 0.9);
	else if (keycode == 87)
		rotate_x(data, -0.05);
	else if (keycode == 84)
		rotate_x(data, 0.05);
	else
		select_func_2(keycode, data);
	return (0);
}

int			main(int argc, char **argv)
{
	t_data	*data;

	if (argc == 2 || argc == 3)
		data = read_data(argv[1]);
	data->argc_2 = 0;
	if (argc == 3)
	{
		data->default_color = read_hex(argv[2]);
		data->argc_2 = 1;
	}
	else
		data->default_color = 0xFFFFFF;
	data->mlx = mlx_init();
	printf("win:[%d]x[%d]\n", data->win_x, data->win_y);
	printf("img:[%d]x[%d]\n", data->win_x, data->win_y);
	data->win = mlx_new_window(data->mlx, data->win_x, data->win_y, "HUI_PIZDA");
	data->img = mlx_new_image(data->mlx, data->win_x, data->win_y);
	data->str = mlx_get_data_addr(data->img, &data->bits, &data->size, &data->end);
	printf("[%d][%d][%d]\n", data->bits, data->size, data->end);
	printf("[%4.2f]\n", data->step);
	draw(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	mlx_hook(data->win, 2, 5, select_func, data);
	mlx_loop(data->mlx);
	return (0);
}



















