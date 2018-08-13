/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgourley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/30 17:01:52 by wgourley          #+#    #+#             */
/*   Updated: 2018/08/13 10:39:20 by wgourley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include <mlx.h>
# define WINDOW_TITLE "Wolf3D"
# include <SDLGF.h>
# include <math_ft.h>

# define MINI_SIZE 20
# define FOV 45
# define VIEW_MAX 100
# define KEY_ESC 53
# define KEY_UP 126
# define KEY_LEFT 123
# define KEY_DOWN 125
# define KEY_RIGHT 124

typedef	struct	s_map
{
	t_value_v	points;
	t_size		size;
}				t_map;

typedef	t_value_v t_player;

t_map		*read_map(char *file);
t_player	get_player();
t_map		*get_map();
void		draw_map();
void		draw_player();

#endif