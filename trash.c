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