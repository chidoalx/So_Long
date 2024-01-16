/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-fagr <ael-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 08:54:18 by ael-fagr          #+#    #+#             */
/*   Updated: 2024/01/16 15:48:08 by ael-fagr         ###   ########.fr       */
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
			return (1);
		set_param(&par);
		par.map = read_map(av[1]);
		if (!par.map)
		{
			printf("Error");
			return (2);
		}
		if (check_map(&par) == 1)
		{
			ft_putstr_fd("invalid map", 1);
			exit(0);
		}
		par.win = mlx_new_window(par.mlx, par.wid * 50, par.hei * 50, "so_long");
		if (!par.win)
			return (3);
		draw_map(&par);
		set_p(&par);
		mlx_hook(par.win, 2, 1L << 0, &key_press, &par);
		mlx_loop(par.mlx);
	}
	else
		ft_putstr_fd("Please check the number of the arguments", 1);
}
