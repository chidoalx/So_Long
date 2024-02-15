/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_touch.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-fagr <ael-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 13:55:45 by ael-fagr          #+#    #+#             */
/*   Updated: 2024/02/01 03:40:01 by ael-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	enemy_touch(t_data *arg, size_t x, size_t y)
{
	if (arg->map[y][x] == 'E' && arg->count_c == 0)
	{
		ft_putstr_fd("You Win", 1);
		exit(0);
	}
	else if (arg->map[y][x] == 'N')
	{
		mlx_put_image_to_window(arg->mlx, arg->win, arg->l, arg->x * 50,
			arg->y * 50);
		mlx_put_image_to_window(arg->mlx, arg->win, arg->grave, x * 50,
			y * 50);
		arg->e_die = 1;
	}
}
