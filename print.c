/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
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
* -4: coord missing
**/

#include "fdf.h"

void		print_error(int err, int row)
{
	ft_putstr("Line #[");
	ft_putnbr(row);
	if (err == 0)
		ft_putendl("] invalid number");
	else if (err == -1)
		ft_putendl("] color is missing");
	else if (err == -2)
		ft_putendl("] invalid color");
	else if (err == -3)
		ft_putendl("] invalid characters");
	else if (err == -4)
		ft_putendl("] wrong number of coordinates");
	else
		ft_putendl("] unknown error");
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
