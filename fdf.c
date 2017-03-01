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

int			main(int argc, char **argv)
{
	void	*mlx;
	void	*win;
	int		**data;

	if (argc != 2)
		return (1);
	data = read_data(argv[1]);
	mlx = mlx_init();
	win = mlx_new_window(mlx, 600, 300, "HUI_PIZDA");
	mlx_loop(mlx);
	return (0);
}