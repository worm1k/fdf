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

/**
*  0: invalid number
* -1: color missing
* -2: invalid color
* -3: invalid characters
**/

#include "fdf.h"

static int			is_space(char *str, int *i)
{
	if (str[*i] == ' ' || str[*i] == '\t')
		while (str[*i] == ' ' || str[*i] == '\t')
			(*i)++;
	else
		return (-3);
	return (1);
}

static int			is_number(char *str, int *i)
{
	if (str[*i] == '-')
		(*i)++;
	if (0 <= str[*i] && str[*i] <= 9)
		while (0 <= str[*i] && str[*i] <= 9)
			(*i)++;
	else
		return (0);
	return (1);
}

static int			is_color(char *str, int *i)
{
	if (str[*i] == '0' && str[*i + 1] == 'x')
	{
		*i += 2;
		if ((0 <= str[*i] && str[*i] <= 9)
		|| ('A' <= str[*i] && str[*i] <= 'F'))
			while ((0 <= str[*i] && str[*i] <= 9)
			|| ('A' <= str[*i] && str[*i] <= 'F'))
				(*i)++;
		else
			return (-2);
	}
	else
		return (-1);
	return (1);
}

static int			count_nums(char *str)
{
	int				i;
	int				res;
	int				err;

	i = 0;
	res = 0;
	while (str[i])
	{
		if ((err = is_number(str, &i)) <= 0)
			return (err);
		if (str[i] == ',')
		{
			i++;
			if ((err = is_color(str, &i)) <= 0)
				return (err);
		}
		if ((err = is_space(str, &i)) <= 0)
			return (err);
		res++;
	}
	return (res);
}

static int			isvalid(char **split)
{
	int				num;
	int				temp;
	int				i;
	int				j;

	num = count_nums(split[0]);

	i = 1;
	return (1);
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

	split = read_chars(path);

	for(int i = 0; split[i]; i++)
	{
		ft_putendl(split[i]);
	}
	return (res);
}
