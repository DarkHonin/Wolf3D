/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgourley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/30 17:01:52 by wgourley          #+#    #+#             */
/*   Updated: 2018/08/06 13:18:35 by wgourley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include <mlx.h>
# define WINDOW_TITLE "Wolf3D"
# include <SDLGF.h>
# include <3dft.h>

typedef struct	s_map
{
	int		**tiles;
	t_len	w;
	t_len	h;
}				t_map;

typedef	struct	s_player
{
	float	x;
	float	y;
	float	d;
}				t_player;

t_map	*read_map(char *file);

#endif