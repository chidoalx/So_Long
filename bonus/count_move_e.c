/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_move_e.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-fagr <ael-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 18:19:46 by ael-fagr          #+#    #+#             */
/*   Updated: 2024/02/07 04:03:57 by ael-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	move_count_e(t_data *arg)
{
	arg->move_count++;
	if (arg->e_die == 1)
	{
		sleep(2);
		ft_putstr_fd("You lose", 1);
		exit (1);
	}
	else if (arg->move_count == 6000)
	{
		move_enemy(arg);
		arg->move_count = 0;
	}
	return (0);
}
