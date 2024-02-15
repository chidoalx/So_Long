/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_enemy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-fagr <ael-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 15:35:32 by ael-fagr          #+#    #+#             */
/*   Updated: 2024/02/07 04:12:14 by ael-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static	int	move_enemy_up_down(t_data *arg, int x)
{
	int	dy;

	dy = 1;
	arg->u_d = rand() % 2;
	if (arg->u_d == 0)
		dy = -1;
	else
		dy = 1;
	x += dy;
	return (x);
}

void	random_move(t_data *arg, int i, int j)
{
	int	a;

	a = move_enemy_up_down(arg, i);
	if (arg->map[a][j] != 'C' && arg->map[a][j] != '1'
		&& arg->map[a][j] != 'E' && arg->map[a][j] != 'N')
	{
		mlx_put_image_to_window(arg->mlx, arg->win, arg->l, j * 50, i * 50);
		arg->map[i][j] = '0';
		mlx_put_image_to_window(arg->mlx, arg->win, arg->enemy, j * 50, a * 50);
		if (arg->map[a][j] == 'P')
		{
			mlx_put_image_to_window(arg->mlx, arg->win, arg->l, arg->x * 50,
			arg->y * 50);
			mlx_put_image_to_window(arg->mlx, arg->win, arg->grave, j * 50,
			a * 50);
			arg->e_die = 1;
		}
		arg->map[a][j] = 'N';
	}
}

int	move_enemy(t_data *arg)
{
	int	i;
	int	j;

	i = 0;
	while (arg->map[i])
	{
		j = 0;
		while (arg->map[i][j])
		{
			if (arg->map[i][j] == 'N')
				random_move(arg, i, j);
			j++;
		}
		i++;
	}
	return (0);
}
