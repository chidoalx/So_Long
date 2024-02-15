/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-fagr <ael-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 02:11:35 by ael-fagr          #+#    #+#             */
/*   Updated: 2024/01/29 14:59:03 by ael-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

size_t	check_border(t_data *arg)
{
	size_t	i;
	size_t	j;

	j = 0;
	arg->wid = ft_strlen(arg->map[j]);
	while (arg->map[j])
		j++;
	arg->hei = j;
	i = 0;
	while (arg->map[i])
	{
		if ((arg->map[i][0] != '1')
			|| arg->map[i][arg->wid - 1] != '1')
			return (1);
		j = 0;
		while (arg->map[i][j])
		{
			if (arg->map[0][j] != '1' || arg->map[arg->hei - 1][j] != '1')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

size_t	check_land(t_data *arg)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (arg->map[i])
	{
		j = 0;
		while (arg->map[i][j])
		{
			if (arg->map[i][j] != '1' && arg->map[i][j] != '0' &&
				arg->map[i][j] != 'C' && arg->map[i][j] != 'E' &&
					arg->map[i][j] != 'P' && arg->map[i][j] != 'N')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

size_t	check_e_and_p(t_data *arg)
{
	size_t	i;
	size_t	j;
	int		n;
	int		m;

	i = 0;
	n = 0;
	m = 0;
	while (arg->map[i])
	{
		j = 0;
		while (arg->map[i][j])
		{
			if (arg->map[i][j] == 'E')
				n++;
			if (arg->map[i][j] == 'P')
				m++;
			j++;
		}
		i++;
	}
	if (m != 1 || n != 1)
		return (1);
	return (0);
}

size_t	check_linght(t_data *arg)
{
	size_t	i;
	size_t	j;

	i = ft_strlen(arg->map[0]);
	j = 0;
	while (arg->map[j])
	{
		if (ft_strlen(arg->map[j]) != i)
			return (1);
		j++;
	}
	return (0);
}

size_t	check_c(t_data *arg)
{
	size_t	i;
	size_t	j;
	int		m;

	i = 0;
	m = 0;
	while (arg->map[i])
	{
		j = 0;
		while (arg->map[i][j])
		{
			if (arg->map[i][j] == 'C')
				m++;
			j++;
		}
		i++;
	}
	if (m < 1)
		return (1);
	return (0);
}
