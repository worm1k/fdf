/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_norme.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abykov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 19:44:03 by abykov            #+#    #+#             */
/*   Updated: 2017/01/16 19:44:04 by abykov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_xy(float *var1, t_point *p1, t_point *p2, t_data *data)
{
	var1[6] = p1->x * data->step;
	var1[7] = p1->y * data->step;
	var1[8] = p2->x * data->step;
	var1[9] = p2->y * data->step;
}

void	ft_startend(int *var0, float *var1)
{
	var0[2] = roundf(var1[6]);
	var0[3] = roundf(var1[7]);
	var0[4] = roundf(var1[8]);
	var0[5] = roundf(var1[9]);
}

void	ft_divide(float *var1, t_point *p1, t_point *p2, int l)
{
	var1[0] = (var1[8] - var1[6]) / l;
	var1[1] = (var1[9] - var1[7]) / l;
	var1[2] = (p2->red - p1->red) / l;
	var1[3] = (p2->green - p1->green) / l;
	var1[4] = (p2->blue - p1->blue) / l;
	var1[5] = (p2->alpha - p1->alpha) / l;
}

void	ft_something(float *var1, t_point *p1)
{
	var1[10] = var1[6];
	var1[11] = var1[7];
	var1[12] = p1->red;
	var1[13] = p1->green;
	var1[14] = p1->blue;
	var1[15] = p1->alpha;
}

void	ft_inc(float *var1)
{
	var1[10] += var1[0];
	var1[11] += var1[1];
	var1[12] += var1[2];
	var1[13] += var1[3];
	var1[14] += var1[4];
	var1[15] += var1[5];
}
