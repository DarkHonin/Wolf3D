/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgourley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 10:20:49 by wgourley          #+#    #+#             */
/*   Updated: 2018/07/21 11:48:49 by wgourley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLD3D_H
# define WOLD3D_H
# define WINDOW_W 800
# define WINDOW_H 600
# define WINDOW_CENTER_X WINDOW_W / 2
# define WINDOW_CENTER_Y WINDOW_H / 2
# define X(point) point->cells[0][0]
# define Y(point) point->cells[0][1]
# define Z(point) point->cells[0][2]
#include <SDL2/SDL.h>
#include <libft.h>
#include <wolf3d.h>
#include <vect_ft.h>
#include <matrix_ft.h>

typedef struct	s_window
{
	int			init;
	SDL_Window	*window_pntr;
	SDL_Renderer *surface;
}				t_window;

typedef t_matrix t_point3;

typedef	struct	s_w3d_surface
{
	t_vector	points;
	int			count;
	t_point3	*closest;
	int			close_index;
	t_point3	*origen;
}				t_w3surface;

typedef struct	s_space
{
	t_vector	entities;
}				t_space;

t_window	*get_window();
void		clear();
void		draw_point(t_point3 *point);
void		draw_surface_lines(t_w3surface *e);
void		draw_surface_points(t_w3surface *e);
SDL_Point	*normilise_point(t_point3 *a);
t_point3	*point3_sum(t_point3 *a, t_point3 *b);
t_point3	**surf_to_point_list(t_w3surface *surf);
t_w3surface **get_space_surfaces(t_space *e);
int			get_surface_count(t_space *a);
void		add_point_to_surface(t_w3surface *s, float x, float y, float z);
void		draw_t_space(t_space *q, void (*draw)(t_w3surface *));
void 		rotate_surf(t_w3surface *s, float deg, t_matrix *(*f)(float));
t_matrix 	*get_rot_matrix_x(float deg);
t_matrix *get_rot_matrix_y(float deg);
t_matrix *get_rot_matrix_z(float deg);
float		dst_from_center(t_point3 *e);

#endif