/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgourley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/30 17:01:52 by wgourley          #+#    #+#             */
/*   Updated: 2018/08/07 12:44:53 by wgourley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include <mlx.h>
# define WINDOW_TITLE "Wolf3D"
# include <SDLGF.h>
# include <3dft.h>

# define KEY_ESC 53
# define KEY_UP 126
# define KEY_LEFT 123
# define KEY_DOWN 125
# define KEY_RIGHT 124

typedef struct	s_map
{
	int		**tiles;
	t_len	w;
	t_len	h;
}				t_map;

typedef	t_point3	t_player;

t_map		*read_map(char *file);
t_player	*get_player();
t_map		*get_map();

#endif