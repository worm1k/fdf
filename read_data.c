/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abykov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 19:44:03 by abykov            #+#    #+#             */
/*   Updated: 2017/01/16 19:44:04 by abykov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static char			**read_char(const char *path)
{
	int				fd;
	int				rows;
	char			*line;
	char			**res;
	int				i;

	fd = open(path, O_RDONLY);
	ft_countrows(fd, &line, &rows);
	res = (char **)malloc(sizeof(char *) * (rows + 1));
	close(fd);
	fd = open(path, O_RDONLY);
	i = 0;
	while (i < rows)
	{
		get_next_line(fd, &res[i]);
		i++;
	}
	res[i] = 0;
	return (res);
}

static void			get_row(t_point *point, char *str, t_data *data, int row)
{
	int				i;

	i = 0;
	while (i < data->cols)
	{
		point[i].x = (float)(i - (data->cols - 1) / 2);
		point[i].y = (float)(row - (data->rows - 1) / 2);
		point[i].z = fd_atoi(&str);
		point[i].x0 = point[i].x;
		point[i].y0 = point[i].y;
		point[i].z0 = point[i].z;
		if (*str == ',')
		{
			str += 3;
			point[i].color = fd_htoi(&str);
		}
		else
			point[i].color = data->default_color;
		if (data->argc_2)
			point[i].color = data->default_color;
		ft_colinit(&point[i]);
		i++;
	}
}

static t_point		**init_struct(int rows, int cols, char **split, t_data *dat)
{
	t_point			**res;
	int				i;

	i = 0;
	res = (t_point **)malloc(sizeof(t_point *) * rows);
	while (i < rows)
	{
		res[i] = (t_point *)malloc(sizeof(t_point) * cols);
		get_row(res[i], split[i], dat, i);
		i++;
	}
	return (res);
}

t_data				*read_data(const char *path, t_data *res)
{
	char			**split;

	split = read_char(path);
	res->cols = isvalid(split, &(res->rows));
	res->point = init_struct(res->rows, res->cols, split, res);
	res->win_x = 1200;
	res->win_y = 1000;
	res->step = 800.0f / (float)(ft_max(res->rows, res->cols) - 1.0f);
	return (res);
}
