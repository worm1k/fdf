/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abykov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 19:44:03 by abykov            #+#    #+#             */
/*   Updated: 2017/01/16 19:44:04 by abykov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			fd_atoi(char **nptr)
{
	int		i;
	int		res;
	int		sign;

	i = 0;
	res = 0;
	sign = 1;
	while ((*nptr)[i] == ' ' || (*nptr)[i] == '\t')
		i++;
	if ((*nptr)[i] == '+')
		i++;
	else if ((*nptr)[i] == '-')
	{
		sign = -1;
		i++;
	}
	while ((*nptr)[i] && '0' <= (*nptr)[i] && (*nptr)[i] <= '9')
	{
		res = res * 10 + (*nptr)[i] - '0';
		i++;
	}
	*nptr += i;
	return (sign * res);
}

static int	tonumber(char c)
{
	if (ft_isdigit(c))
		return (c - '0');
	else if (ft_islower(c))
		return (c - 'a' + 10);
	else if (ft_isupper(c))
		return (c - 'A' + 10);
	return (0xDEADBEEF);
}

int			fd_htoi(char **nptr)
{
	int		i;
	int		res;

	i = 0;
	res = 0;
	while (ft_isalnum((*nptr)[i]))
	{
		res = res * 16 + tonumber((*nptr)[i]);
		i++;
	}
	*nptr += i;
	return (res);
}