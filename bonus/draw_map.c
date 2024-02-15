/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-fagr <ael-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 11:43:08 by ael-fagr          #+#    #+#             */
/*   Updated: 2024/01/25 00:25:14 by ael-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static	void	set_enemy(t_data *arg)
{
	if (arg->map[arg->j][arg->i] == 'N')
	{
		mlx_put_image_to_window(arg->mlx, arg->win, arg->enemy,
			arg->i * 50, arg->j * 50);
	}
	else
		mlx_put_image_to_window(arg->mlx, arg->win, arg->l,
			arg->i * 50, arg->j * 50);
}

void	draw_map(t_data *arg)
{
	while (arg->map[arg->j])
	{
		arg->i = 0;
		while (arg->map[arg->j][arg->i])
		{
			if (arg->map[arg->j][arg->i] == '1')
				mlx_put_image_to_window(arg->mlx, arg->win, arg->w,
					arg->i * 50, arg->j * 50);
			else if (arg->map[arg->j][arg->i] == 'P')
				mlx_put_image_to_window(arg->mlx, arg->win, arg->p_d,
					arg->i * 50, arg->j * 50);
			else if (arg->map[arg->j][arg->i] == '0'
				|| arg->map[arg->j][arg->i] == 'N')
				set_enemy(arg);
			else if (arg->map[arg->j][arg->i] == 'E')
				mlx_put_image_to_window(arg->mlx, arg->win, arg->e, arg->i * 50,
					arg->j * 50);
			else if (arg->map[arg->j][arg->i] == 'C')
				mlx_put_image_to_window(arg->mlx, arg->win, arg->c, arg->i * 50,
					arg->j * 50);
			arg->i++;
		}
		arg->j++;
	}
}
