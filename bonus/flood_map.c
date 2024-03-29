/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-fagr <ael-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 23:10:15 by ael-fagr          #+#    #+#             */
/*   Updated: 2024/02/05 03:22:50 by ael-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	check_square_map(t_data *arg)
{
	if (arg->hei == arg->wid)
		return (1);
	else
		return (0);
}

static	void	p_e_position(t_data *arg)
{
	size_t	i;
	size_t	j;

	j = 0;
	while (arg->map[j])
	{
		i = 0;
		while (arg->map[j][i])
		{
			if (arg->map[j][i] == 'P')
			{
				arg->x = i;
				arg->y = j;
			}
			else if (arg->map[j][i] == 'E')
			{
				arg->e_x_p = i;
				arg->e_y_p = j;
			}
			i++;
		}
		j++;
	}
}

static	void	copy_map(t_data *arg)
{
	size_t	i;
	size_t	j;

	i = 0;
	arg->cp_mp = (char **)malloc(sizeof(char *) * (arg->hei + 1));
	while (arg->map[i])
	{
		arg->cp_mp[i] = (char *)malloc((arg->wid + 1) * sizeof(char));
		j = 0;
		while (arg->map[i][j])
		{
			arg->cp_mp[i][j] = arg->map[i][j];
			j++;
		}
		arg->cp_mp[i][j] = '\0';
		i++;
	}
	arg->cp_mp[i] = NULL;
}

static	void	flood_fill(t_data *arg, size_t x, size_t y)
{
	if (arg->cp_mp[y][x] == '1' || arg->cp_mp[y][x] == 'E')
		return ;
	else
	{
		arg->cp_mp[y][x] = '1';
		flood_fill(arg, x + 1, y);
		flood_fill(arg, x - 1, y);
		flood_fill(arg, x, y + 1);
		flood_fill(arg, x, y - 1);
	}
}

size_t	check_flood(t_data *arg)
{
	size_t	i;
	size_t	j;

	i = 0;
	set_hei_and_wid(arg);
	copy_map(arg);
	p_e_position(arg);
	flood_fill(arg, arg->x, arg->y);
	while (arg->cp_mp[i])
	{
		j = 0;
		while (arg->cp_mp[i][j])
		{
			if (arg->cp_mp[i][j] != '1' && arg->cp_mp[i][j] != '0'
				&& arg->cp_mp[i][j] != 'N' && arg->cp_mp[i][j] != 'E')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
