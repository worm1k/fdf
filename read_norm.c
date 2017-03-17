/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_norm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abykov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 19:44:03 by abykov            #+#    #+#             */
/*   Updated: 2017/01/16 19:44:04 by abykov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_colinit(t_point *point)
{
	point->blue = point->color % 256;
	point->green = point->color / 256 % 256;
	point->red = point->color / 256 / 256 % 256;
	point->alpha = point->color / 256 / 256 / 256;
}

void	ft_countrows(int fd, char **line, int *rows)
{
	*rows = 0;
	if (fd < 0)
	{
		ft_putendl("#Error: File does not exist");
		exit(0);
	}
	while (get_next_line(fd, line) > 0)
	{
		(*line) ? (free(*line)) : (0);
		*line = 0;
		(*rows)++;
	}
	if (*rows == 0)
	{
		ft_putendl("#Error: Empty map");
		exit(0);
	}
}
