/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-fagr <ael-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 05:43:32 by ael-fagr          #+#    #+#             */
/*   Updated: 2024/01/15 17:05:36 by ael-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <math.h>
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
	void	*mlx;
	void	*win;
	void	*w;
	void	*l;
	void	*c;
	void	*e;
	void	*e_o;
	void	*p_r;
	void	*p_l;
	void	*p_u;
	void	*p_d;
	int		p_posision;
	int		fd;
	int		x;
	int		y;
	int		i;
	int		j;
	int		e_x_p;
	int		e_y_p;
	int		count_c;
	int		move;
	int		hei;
	int		wid;
	char	**map;
}	t_data;

void	set_param(t_data *args);
void	set_p(t_data *arg);
char	*ft_strchr(char *s, int c);
size_t	ft_strlen(char *s);
char	*get_next_line(int fd);
size_t	ft_strlen(char *s);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(char *s);
int		key_press(int keycode, t_data *par);
void	draw_map(t_data *arg);
char	**read_map(char *p);
char	**ft_split(char const *s, char c);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putchar_fd(char c, int fd);
int		check_map(t_data *arg);

#endif