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
#include <stdio.h>

struct dick
{
	int len;
	int x[10];
};

int			**read_data(char *path)
{
	int		fd;
	int		i;
	char	*line;
	int		**res;

	i = 0;
	fd = open(path, O_RDONLY);
	while (get_next_line(fd, &line))
	{
		(line) ? (free(line)) : (0);
		line = 0;
		i++;
	}
	return (0);
}

int			main(int argc, char **argv)
{
	void	*mlx;
	void	*win;
	int		**data;
	struct dick st;

	st.len = 20;
	printf("%d\n", st.len);

	if (argc != 2)
		return (1);
//	data = read_data(argv[1]);
	mlx = mlx_init();
	win = mlx_new_window(mlx, 600, 300, "HUI_PIZDA");
	mlx_loop(mlx);
	return (0);
}