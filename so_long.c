/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-fagr <ael-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 08:54:18 by ael-fagr          #+#    #+#             */
/*   Updated: 2024/01/17 03:55:33 by ael-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_data	par;

	if (ac == 2)
	{
		par.mlx = mlx_init();
		if (!par.mlx)
			return (2);
		set_param(&par);
		par.map = read_map(av[1]);
		if (!par.map)
			return (ft_putstr_fd("invalid map", 2), 2);
		if (check_map(&par) == 1)
		{
			ft_putstr_fd("invalid map", 1);
			exit(0);
		}
		par.win = mlx_new_window(par.mlx, par.wid * 50, par.hei * 50, "mashle");
		if (!par.win)
			return (2);
		draw_map(&par);
		set_p(&par);
		mlx_hook(par.win, 2, 1L << 0, &key_press, &par);
		mlx_loop(par.mlx);
	}
}
