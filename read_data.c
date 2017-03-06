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
	res = (char **)malloc(sizeof(char *) * rows);
	close(fd);
	fd = open(path, O_RDONLY);
	i = 0;
	while (i < rows)
	{
		get_next_line(fd, &res[i]);
		// ft_putendl(res[i]);
		i++;
	}
	return (res);
}

static char			**read_chars(const char *path)
{
	int				fd;
	char			*buf;
	char			*temp;
	char			*del;

	fd = open(path, O_RDONLY);
	buf = ft_strnew(BUFF_SIZE);
	temp = ft_strnew(BUFF_SIZE);
	read(fd, buf, BUFF_SIZE);
	while (read(fd, temp, BUFF_SIZE) > 0)
	{
		del = buf;
		buf = ft_strjoin(buf, temp);
		(del) ? (free(del)) : (0);
		ft_strclr(temp);
	}
	close(fd);
	return (ft_strsplit(buf, '\n'));
}

t_data				**read_data(const char *path)
{
	char			**split;
	t_data			**res;
	int				rows;
	int				cols;

	split = read_char(path);
	cols = isvalid(split, &rows);
	printf("[%d]x[%d]\n", rows, cols);

	return (res);
}






