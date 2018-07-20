/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgourley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 10:20:49 by wgourley          #+#    #+#             */
/*   Updated: 2018/07/20 13:55:54 by wgourley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLD3D_H
# define WOLD3D_H
# define WINDOW_W 800
# define WINDOW_H 600
#include <SDL2/SDL.h>
#include <libft.h>
#include <wolf3d.h>

typedef struct	s_window
{
	int			init;
	SDL_Window	*window_pntr;
	SDL_Renderer *surface;
}				t_window;

typedef	struct	s_point3
{
	float x;
	float y;
	float z;
}				t_point3;

typedef	struct	s_w3d_surface
{
	t_point3	*points;
	int			count;
	t_point3	center;
}				t_w3surface;

t_window	*get_window();
void		clear();
void		draw_point(t_point3 *point);
void		draw_surface_lines(t_w3surface *e);

#endif