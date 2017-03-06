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
	if (str[*i] == '\0')
		return (1);
	if (str[*i] == ' ' || str[*i] == '\t')
		while (str[*i] == ' ' || str[*i] == '\t')
			(*i)++;
	else
	{
		printf("I:[%d][%c]\n", *i, str[*i]);
		return (-3);
	}
	return (1);
}

static int			is_number(char *str, int *i)
{
	if (str[*i] == '-')
		(*i)++;
	if ('0' <= str[*i] && str[*i] <= '9')
		while ('0' <= str[*i] && str[*i] <= '9')
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
		if (('0' <= str[*i] && str[*i] <= '9')
		|| ('A' <= str[*i] && str[*i] <= 'F')
		|| ('a' <= str[*i] && str[*i] <= 'f'))
			while (('0' <= str[*i] && str[*i] <= '9')
			|| ('A' <= str[*i] && str[*i] <= 'F')
			|| ('a' <= str[*i] && str[*i] <= 'f'))
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
	while (str[i] == ' ' || str[i] == '\t')
		i++;
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

int					isvalid(char **split, int *rows)
{
	int				num;
	int				temp;
	int				i;

	if ((num = count_nums(split[0])) <= 0)
	{
		print_error(num, 1);
		return (0);
	}
	i = 1;
	while (split[i])
	{
		temp = count_nums(split[i]);
		if (num != temp)
		{
			print_error(-4, i);
			printf("LINE[%d][%+d]\n", i, num - temp);
			return (0);
		}
		i++;
	}
	*rows = i;
	return (num);
}

