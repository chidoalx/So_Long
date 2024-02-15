/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-fagr <ael-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 05:43:32 by ael-fagr          #+#    #+#             */
/*   Updated: 2024/02/09 11:50:56 by ael-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <math.h>
# include <time.h>
# include "mlx.h"
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1486969768
# endif

typedef struct s_data
{
	void		*mlx;
	void		*win;
	void		*w;
	void		*l;
	void		*c;
	void		*e;
	void		*e_o;
	void		*p_r;
	void		*p_l;
	void		*p_u;
	void		*p_d;
	void		*grave;
	void		*enemy;
	int			fd;
	int			x;
	int			y;
	int			i;
	int			j;
	int			u_d;
	int			e_x_p;
	int			e_y_p;
	int			e_die;
	int			count_c;
	int			move_count;
	int			move;
	size_t		hei;
	size_t		wid;
	char		**map;
	char		**cp_mp;
	char		*str;
}	t_data;

void	set_param(t_data *args);
void	set_p(t_data *arg);
char	*ft_strchr(char *s, int c);
size_t	ft_strlen(char *s);
char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
int		key_press(int keycode, t_data *par);
void	draw_map(t_data *arg);
char	**read_map_bonus(char *p);
char	**ft_split(char *s, char c);
char	*ft_itoa(int nbr);
int		check_map(t_data *arg);
size_t	check_flood(t_data *arg);
void	set_hei_and_wid(t_data *arg);
void	ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
void	enemy_touch(t_data *arg, size_t x, size_t y);
int		move_enemy(t_data *arg);
int		move_count_e(t_data *arg);
int		check_square_map(t_data *arg);
size_t	check_c(t_data *arg);
size_t	check_linght(t_data *arg);
size_t	check_land(t_data *arg);
size_t	check_border(t_data *arg);
size_t	check_e_and_p(t_data *arg);
void	random_move(t_data *arg, int i, int j);
#endif