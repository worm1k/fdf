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

// static char			**read_chars(const char *path)
// {
// 	int				fd;
// 	char			*buf;
// 	char			*temp;
// 	char			*del;

// 	fd = open(path, O_RDONLY);
// 	buf = ft_strnew(BUFF_SIZE);
// 	temp = ft_strnew(BUFF_SIZE);
// 	read(fd, buf, BUFF_SIZE);
// 	while (read(fd, temp, BUFF_SIZE) > 0)
// 	{
// 		del = buf;
// 		buf = ft_strjoin(buf, temp);
// 		(del) ? (free(del)) : (0);
// 		ft_strclr(temp);
// 	}
// 	close(fd);
// 	return (ft_strsplit(buf, '\n'));
// }

static char			**read_char(const char *path)
{
	int				fd;
	int				rows;
	char			*line;
	char			**res;
	int				i;

	fd = open(path, O_RDONLY);
	rows = 0;
	while (get_next_line(fd, &line) > 0)
	{
		(line) ? (free(line)) : (0);
		line = 0;
		rows++;
	}
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
		point[i].x = (float)(i - (data->cols - 1 ) / 2);
		point[i].y = (float)(row - (data->rows - 1 ) / 2);
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
			point[i].color = 0xFFFFFF;
		i++;
	}
}

static t_point		**init_struct(int rows, int cols, char **split, t_data *data)
{
	t_point			**res;
	int				i;

	i = 0;
	printf("malloc(%d * %d)\n", cols, rows);
	res = (t_point **)malloc(sizeof(t_point *) * rows);
	while (i < rows)
	{
		res[i] = (t_point *)malloc(sizeof(t_point) * cols);
		get_row(res[i], split[i], data, i);
		i++;
	}
	return (res);
}

t_data				*read_data(const char *path)
{
	char			**split;
	t_data			*res;

	res = (t_data *)malloc(sizeof(t_data));
	split = read_char(path);
	res->cols = isvalid(split, &(res->rows));
	if (res->cols < 1)
		exit (0);
	printf("[%d]x[%d]\n", res->rows, res->cols);
	res->point = init_struct(res->rows, res->cols, split, res);
	// res->x_max = res->step * (res->cols - 1);
	// res->y_max = res->step * (res->rows - 1);
	res->win_x = 1000;
	res->win_y = 1000;
	res->step = 800.0 / (float)(ft_max(res->rows, res->cols) - 1);

	return (res);
}






