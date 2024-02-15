/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movemont.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-fagr <ael-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 11:42:46 by ael-fagr          #+#    #+#             */
/*   Updated: 2024/02/09 12:40:27 by ael-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static	void	move_up(t_data *data)
{
	enemy_touch(data, data->x, data->y - 1);
	if (data->map[data->y - 1][data->x] != 'E'
			&& data->map[data->y - 1][data->x] != 'N')
	{
		if (data->map[data->y - 1][data->x] == 'C')
		{
			data->count_c--;
			data->map[data->y - 1][data->x] = '0';
		}
		mlx_put_image_to_window(data->mlx, data->win, data->l, data->x * 50,
			data->y * 50);
		data->map[data->y][data->x] = '0';
		data->y -= 1;
		mlx_put_image_to_window(data->mlx, data->win, data->p_u, data->x * 50,
			data->y * 50);
		data->map[data->y][data->x] = 'P';
		data->move += 1;
		data->str = ft_itoa(data->move);
		mlx_put_image_to_window(data->mlx, data->win, data->w, 50, 0);
		mlx_string_put(data->mlx, data->win, 50, 25, 0xFFFF0F, data->str);
		free(data->str);
	}
	if (data->count_c == 0)
		mlx_put_image_to_window(data->mlx, data->win, data->e_o,
			data->e_x_p * 50, data->e_y_p * 50);
}

static	void	move_down(t_data *data)
{
	enemy_touch(data, data->x, data->y + 1);
	if (data->map[data->y + 1][data->x] != 'E'
			&& data->map[data->y + 1][data->x] != 'N')
	{
		if (data->map[data->y + 1][data->x] == 'C')
		{
			data->count_c--;
			data->map[data->y + 1][data->x] = '0';
		}
		mlx_put_image_to_window(data->mlx, data->win, data->l, data->x * 50,
			data->y * 50);
		data->map[data->y][data->x] = '0';
		data->y += 1;
		mlx_put_image_to_window(data->mlx, data->win, data->p_d, data->x * 50,
			data->y * 50);
		data->map[data->y][data->x] = 'P';
		data->move += 1;
		data->str = ft_itoa(data->move);
		mlx_put_image_to_window(data->mlx, data->win, data->w, 50, 0);
		mlx_string_put(data->mlx, data->win, 50, 25, 0xFFFF0F, data->str);
		free(data->str);
	}
	if (data->count_c == 0)
		mlx_put_image_to_window(data->mlx, data->win, data->e_o,
			data->e_x_p * 50, data->e_y_p * 50);
}

static	void	move_left(t_data *data)
{
	enemy_touch(data, data->x - 1, data->y);
	if (data->map[data->y][data->x - 1] != 'E'
		&& data->map[data->y][data->x - 1] != 'N')
	{
		if (data->map[data->y][data->x - 1] == 'C')
		{
			data->count_c--;
			data->map[data->y][data->x - 1] = '0';
		}
		mlx_put_image_to_window(data->mlx, data->win, data->l, data->x * 50,
			data->y * 50);
		data->map[data->y][data->x] = '0';
		data->x -= 1;
		mlx_put_image_to_window(data->mlx, data->win, data->p_l, data->x * 50,
			data->y * 50);
		data->move += 1;
		data->map[data->y][data->x] = 'P';
		data->str = ft_itoa(data->move);
		mlx_put_image_to_window(data->mlx, data->win, data->w, 50, 0);
		mlx_string_put(data->mlx, data->win, 50, 25, 0xFFFF0F, data->str);
		free(data->str);
	}
	if (data->count_c == 0)
		mlx_put_image_to_window(data->mlx, data->win, data->e_o,
			data->e_x_p * 50, data->e_y_p * 50);
}

static	void	move_right(t_data *data)
{
	enemy_touch(data, data->x + 1, data->y);
	if (data->map[data->y][data->x + 1] != 'E'
		&& data->map[data->y][data->x + 1] != 'N')
	{
		if (data->map[data->y][data->x + 1] == 'C')
		{
			data->count_c--;
			data->map[data->y][data->x + 1] = '0';
		}
		mlx_put_image_to_window(data->mlx, data->win, data->l, data->x * 50,
			data->y * 50);
		data->map[data->y][data->x] = '0';
		data->x += 1;
		mlx_put_image_to_window(data->mlx, data->win, data->p_r, data->x * 50,
			data->y * 50);
		data->map[data->y][data->x] = 'P';
		data->move += 1;
		data->str = ft_itoa(data->move);
		mlx_put_image_to_window(data->mlx, data->win, data->w, 50, 0);
		mlx_string_put(data->mlx, data->win, 50, 25, 0xFFFF0F, data->str);
		free(data->str);
	}
	if (data->count_c == 0)
		mlx_put_image_to_window(data->mlx, data->win, data->e_o,
			data->e_x_p * 50, data->e_y_p * 50);
}

int	key_press(int keycode, t_data *par)
{
	if (keycode ==  65362 || keycode == 122)
	{
		if (par->map[par->y - 1][par->x] != '1')
			move_up(par);
	}
	else if (keycode == 65364 || keycode == 115)
	{
		if (par->map[par->y + 1][par->x] != '1')
			move_down(par);
	}
	else if (keycode == 65363 || keycode == 100)
	{
		if (par->map[par->y][par->x + 1] != '1')
			move_right(par);
	}
	else if (keycode == 65361 || keycode == 113)
	{
		if (par->map[par->y][par->x - 1] != '1')
			move_left(par);
	}
	else if (keycode == 53)
		exit(0);
	return (0);
}
