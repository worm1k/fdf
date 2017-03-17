/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trash.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abykov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 19:44:03 by abykov            #+#    #+#             */
/*   Updated: 2017/01/16 19:44:04 by abykov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		wolf(void *mlx, void *win)
{
	int w = 300, h = 300;
	int	bpp, sl, end;

	void *img = mlx_xpm_file_to_image(mlx, "../Downloads/gun.xpm.txt", &w, &h);
	mlx_put_image_to_window(mlx, win, img, 100, 100);
	printf("[W]:[%d]\n", w);
	printf("[H]:[%d]\n", h);
	char *str = mlx_get_data_addr(img, &bpp, &sl, &end);

	printf("[STR]:%d\n", ((int *)str)[0]);
	printf("[BPP]:%d\n", bpp);
	printf(" [SL]:%d\n", sl);
	printf("[END]:%d\n", end);
}

void		idinahuipidor(void *mlx, void *win)
{
	mlx_string_put(mlx, win, 100, 100, 0xFF0000, "IDI_NAHUI");
	mlx_string_put(mlx, win, 115, 120, 0xFFFF00, "P");
	mlx_string_put(mlx, win, 130, 120, 0x00FF00, "I");
	mlx_string_put(mlx, win, 145, 120, 0x00FFFF, "D");
	mlx_string_put(mlx, win, 160, 120, 0x0000FF, "O");
	mlx_string_put(mlx, win, 175, 120, 0xFF00FF, "R");
}

void	print_struct(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->rows)
	{
		j = 0;
		while (j < data->cols)
		{
			printf("%f", data->point[i][j].z);
			if (data->point[i][j].color != 0xFFFFFF)
				printf(",%x", data->point[i][j].color);
			j++;
			printf("  ");
		}
		printf("\n");
		i++;
	}
}

/**
* static void		dda_line1(t_data *data, t_point *p1, t_point *p2)
* {
* 	int			i, L, xstart, ystart, xend, yend;
* 	float		dx, dy, dr, dg, db, da, x1, x2, y1, y2, xi, yi, ri, gi, bi, ai;
* 	float		var1[16];
* 	unsigned	color;
* 
* 	x1 = p1->x * data->step;
* 	y1 = p1->y * data->step;
* 	x2 = p2->x * data->step;
* 	y2 = p2->y * data->step;
* 	xstart = roundf(x1);
* 	ystart = roundf(y1);
* 	xend = roundf(x2);
* 	yend = roundf(y2);
* 	L = ft_max(abs(xend-xstart), abs(yend-ystart));
* 	if (L == 0)
* 		return ;
* 	dx = (x2-x1) / L;
* 	dy = (y2-y1) / L;
* 	dr = (p2->red - p1->red) / L;
* 	dg = (p2->green - p1->green) / L;
* 	db = (p2->blue - p1->blue) / L;
* 	da = (p2->alpha - p1->alpha) / L;
* 	i = 0;
* 	img_pixel_put(data, roundf(x1), roundf(y1), p1->color);
* 	xi = x1;
* 	yi = y1;
* 	ri = p1->red;
* 	gi = p1->green;
* 	bi = p1->blue;
* 	ai = p1->alpha;
* 	i++;
* 	while (i < L)
* 	{
* 		color = get_color(roundf(ri + dr), roundf(gi + dg), roundf(bi + db), roundf(ai + da));
* 		img_pixel_put(data, roundf(xi + dx), roundf(yi + dy), color);
* 		xi = xi + dx;
* 		yi = yi + dy;
* 		ri = ri + dr;
* 		gi = gi + dg;
* 		bi = bi + db;
* 		ai = ai + da;
* 		i++;
* 	}
* 	img_pixel_put(data, roundf(x2), roundf(y2), p2->color);
* }
**/