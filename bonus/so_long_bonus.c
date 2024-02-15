/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-fagr <ael-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 08:54:18 by ael-fagr          #+#    #+#             */
/*   Updated: 2024/02/09 11:51:55 by ael-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static	int	ft_close(t_data *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
	return (0);
}

int	main(int ac, char **av)
{
	t_data	par;

	if (ac == 2)
	{
		par.mlx = mlx_init();
		if (!par.mlx)
			return (2);
		set_param(&par);
		par.map = read_map_bonus(av[1]);
		if (!par.map)
			return (free(par.map), ft_putstr_fd("Error\ninvalid map", 1), 2);
		if (check_map(&par) == 1)
			exit (1);
		par.win = mlx_new_window(par.mlx, par.wid * 50, par.hei * 50, "mashle");
		if (!par.win)
			return (2);
		draw_map(&par);
		set_p(&par);
		mlx_string_put(par.mlx, par.win, 0, 25, 0x00F0F0, "move:");
		mlx_loop_hook(par.mlx, &move_count_e, &par);
		mlx_hook(par.win, 2, 1L << 0, &key_press, &par);
		mlx_hook(par.win, 17, 0L, &ft_close, &par);
		mlx_loop(par.mlx);
	}
}
