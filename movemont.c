/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movemont.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-fagr <ael-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 11:42:46 by ael-fagr          #+#    #+#             */
/*   Updated: 2024/01/25 00:15:05 by ael-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static	void	move_up(t_data *data)
{
	win_exit(data, data->x, data->y - 1);
	if (data->map[data->y - 1][data->x] != 'E')
	{
		if (data->map[data->y - 1][data->x] == 'C')
		{
			data->count_c--;
			data->map[data->y - 1][data->x] = '0';
		}
		mlx_put_image_to_window(data->mlx, data->win, data->l, data->x * 50,
			data->y * 50);
		data->y -= 1;
		mlx_put_image_to_window(data->mlx, data->win, data->l, data->x * 50,
			data->y * 50);
		mlx_put_image_to_window(data->mlx, data->win, data->p_d, data->x * 50,
			data->y * 50);
		data->move += 1;
		ft_putnbr_fd(data->move, 1);
		ft_putchar_fd('\n', 1);
	}
	if (data->count_c == 0)
		mlx_put_image_to_window(data->mlx, data->win, data->e_o,
			data->e_x_p * 50, data->e_y_p * 50);
}

static	void	move_down(t_data *data)
{
	win_exit(data, data->x, data->y + 1);
	if (data->map[data->y + 1][data->x] != 'E')
	{
		if (data->map[data->y + 1][data->x] == 'C')
		{
			data->count_c--;
			data->map[data->y + 1][data->x] = '0';
		}
		mlx_put_image_to_window(data->mlx, data->win, data->l, data->x * 50,
			data->y * 50);
		data->y += 1;
		mlx_put_image_to_window(data->mlx, data->win, data->l, data->x * 50,
			data->y * 50);
		mlx_put_image_to_window(data->mlx, data->win, data->p_d, data->x * 50,
			data->y * 50);
		data->move += 1;
		ft_putnbr_fd(data->move, 1);
		ft_putchar_fd('\n', 1);
	}
	if (data->count_c == 0)
		mlx_put_image_to_window(data->mlx, data->win, data->e_o,
			data->e_x_p * 50, data->e_y_p * 50);
}

static	void	move_left(t_data *data)
{
	win_exit(data, data->x - 1, data->y);
	if (data->map[data->y][data->x - 1] != 'E')
	{
		if (data->map[data->y][data->x - 1] == 'C')
		{
			data->count_c--;
			data->map[data->y][data->x - 1] = '0';
		}
		mlx_put_image_to_window(data->mlx, data->win, data->l, data->x * 50,
			data->y * 50);
		data->x -= 1;
		mlx_put_image_to_window(data->mlx, data->win, data->l, data->x * 50,
			data->y * 50);
		mlx_put_image_to_window(data->mlx, data->win, data->p_d, data->x * 50,
			data->y * 50);
		data->move += 1;
		ft_putnbr_fd(data->move, 1);
		ft_putchar_fd('\n', 1);
	}
	if (data->count_c == 0)
		mlx_put_image_to_window(data->mlx, data->win, data->e_o,
			data->e_x_p * 50, data->e_y_p * 50);
}

static	void	move_right(t_data *data)
{
	win_exit(data, data->x + 1, data->y);
	if (data->map[data->y][data->x + 1] != 'E')
	{
		if (data->map[data->y][data->x + 1] == 'C')
		{
			data->count_c--;
			data->map[data->y][data->x + 1] = '0';
		}
		mlx_put_image_to_window(data->mlx, data->win, data->l, data->x * 50,
			data->y * 50);
		data->x += 1;
		mlx_put_image_to_window(data->mlx, data->win, data->l, data->x * 50,
			data->y * 50);
		mlx_put_image_to_window(data->mlx, data->win, data->p_d, data->x * 50,
			data->y * 50);
		data->move += 1;
		ft_putnbr_fd(data->move, 1);
		ft_putchar_fd('\n', 1);
	}
	if (data->count_c == 0)
		mlx_put_image_to_window(data->mlx, data->win, data->e_o,
			data->e_x_p * 50, data->e_y_p * 50);
}

int	key_press(int keycode, t_data *par)
{
	if (keycode == 13 || keycode == 126)
	{
		if (par->map[par->y - 1][par->x] != '1')
			move_up(par);
	}
	else if (keycode == 1 || keycode == 125)
	{
		if (par->map[par->y + 1][par->x] != '1')
			move_down(par);
	}
	else if (keycode == 2 || keycode == 124)
	{
		if (par->map[par->y][par->x + 1] != '1')
			move_right(par);
	}
	else if (keycode == 0 || keycode == 123)
	{
		if (par->map[par->y][par->x - 1] != '1')
			move_left(par);
	}
	else if (keycode == 53)
		exit(0);
	return (0);
}
