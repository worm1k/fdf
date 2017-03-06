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

int 	ft_max(int a, int b)
{
	return (a > b) ? (a) : (b);
}

void dda_line (float x1, float y1, float x2, float y2, void *mlx, void *win)
{
	int		i, L, xstart, ystart, xend, yend;
	float	dX, dY, x[1000], y[1000];

	xstart = roundf(x1);
	ystart = roundf(y1);
	xend = roundf(x2);
	yend = roundf(y2);
	L = ft_max(abs(xend-xstart), abs(yend-ystart));
	dX = (x2-x1) / L;
	dY = (y2-y1) / L;
	i = 0;
	x[i] = x1;
	y[i] = y1;
	i++;
	while (i < L)
	{
	x[i] = x[i-1] + dX;
	y[i] = y[i-1] + dY;
	i++;
	}
	x[i] = x2;
	y[i] = y2;
	/* Output: -----------------------*/
	i = 0;
	while (i <= L)
	{
		mlx_pixel_put (mlx, win, roundf(x[i]), roundf(y[i]), 0xffffff);
	i++;
	}
	/* -------------------------------*/
}

int			main(int argc, char **argv)
{
	void	*mlx;
	void	*win;
	t_data	**data;

	//data = read_data(argv[1]);
	//mlx = mlx_init();
	//win = mlx_new_window(mlx, 600, 300, "HUI_PIZDA");
	if (argc == 2)
		read_data(argv[1]);
	/*
	mlx_string_put(mlx, win, 100, 100, 0xFF0000, "IDI_NAHUI");
	mlx_string_put(mlx, win, 115, 120, 0xFFFF00, "P");
	mlx_string_put(mlx, win, 130, 120, 0x00FF00, "I");
	mlx_string_put(mlx, win, 145, 120, 0x00FFFF, "D");
	mlx_string_put(mlx, win, 160, 120, 0x0000FF, "O");
	mlx_string_put(mlx, win, 175, 120, 0xFF00FF, "R");
	*/
	//dda_line(10, 10, 500, 15, mlx, win);
	
	//mlx_loop(mlx);
	return (0);
}



















