/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-fagr <ael-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 16:51:28 by ael-fagr          #+#    #+#             */
/*   Updated: 2024/02/09 11:37:35 by ael-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	check_map(t_data *arg)
{
	if (check_border(arg) == 1)
		return (ft_putstr_fd("Error\ncheck boder", 2), 1);
	else if (check_land(arg) == 1)
		return (ft_putstr_fd("Error\ncheck land", 2), 1);
	else if (check_e_and_p(arg) == 1)
		return (ft_putstr_fd("Error\ncheck characters", 2), 1);
	else if (check_linght(arg) == 1)
		return (ft_putstr_fd("Error\ncheck lenght", 2), 1);
	else if (check_flood(arg) == 1)
		return (ft_putstr_fd("Error\ncheck flood", 2), 1);
	else if (check_c(arg) == 1)
		return (ft_putstr_fd("Error\ncheck number of 0 or C", 1), 1);
	else if (check_square_map(arg) == 1)
		return (ft_putstr_fd("Error\ninvalid map (square map)", 2), 1);
	else
		return (0);
}
