/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_funct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgourley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 13:44:34 by wgourley          #+#    #+#             */
/*   Updated: 2018/07/21 11:47:44 by wgourley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

void	draw_point(t_point3 *point)
{
	t_window *win;

	win = get_window();
	SDL_RenderDrawPoint(win->surface, point->cells[0][0]/point->cells[0][2], point->cells[0][1]/point->cells[0][2]);
}

void	draw_surface_points(t_w3surface *e)
{
	int x;
	t_point3		**nodes;

	nodes = surf_to_point_list(e);
	x = 0;
	while (x < e->count)
		draw_point(nodes[x++]);
}

void	draw_line(t_point3 *a, t_point3 *b)
{
	SDL_Point *na;
	SDL_Point *nb;

	na = normilise_point(a);
	nb = normilise_point(b);
	SDL_RenderDrawLine(get_window()->surface, na->x, na->y, nb->x, nb->y);
	free(na);
	free(nb);
}

void	draw_surface_lines(t_w3surface *e)
{
	int x;
	t_point3	**nodes;
	SDL_Point	*norm1;
	SDL_Point	*norm2;

	if (e->count <= 1)
		return ;
	x = 0;
	nodes = surf_to_point_list(e);
	while (x < e->count)
	{
		if (nodes[x] == e->closest)
				SDL_SetRenderDrawColor(get_window()->surface, 255, 0, 0, SDL_ALPHA_OPAQUE);
			else
				SDL_SetRenderDrawColor(get_window()->surface, 255, 255, 255, SDL_ALPHA_OPAQUE);
		if (x > 0)
			draw_line(point3_sum(nodes[x - 1], e->origen), point3_sum(nodes[x], e->origen));
		else
			draw_line(point3_sum(nodes[e->count - 1], e->origen), point3_sum(nodes[x], e->origen));
		x++;
	}
}

void	draw_t_space(t_space *q, void (*draw)(t_w3surface *))
{
	t_w3surface **kids;
	SDL_Point *pp;
	int max;
	int x;

	kids = get_space_surfaces(q);
	max = get_surface_count(q);
	x = 0;
	while (x < max)
	{
		draw(kids[x]);
		pp = normilise_point(kids[x]->origen);
		SDL_SetRenderDrawColor(get_window()->surface, 255, 0, 0, SDL_ALPHA_OPAQUE);
		SDL_RenderDrawLine(get_window()->surface, pp->x, pp->y, pp->x - 20, pp->y);
		SDL_SetRenderDrawColor(get_window()->surface, 0, 255, 0, SDL_ALPHA_OPAQUE);
		SDL_RenderDrawLine(get_window()->surface, pp->x, pp->y, pp->x, pp->y - 20);
		x++;
	}
	
}