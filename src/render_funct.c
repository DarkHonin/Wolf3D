/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_funct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgourley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 13:44:34 by wgourley          #+#    #+#             */
/*   Updated: 2018/07/20 14:18:44 by wgourley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

void	draw_point(t_point3 *point)
{
	t_window *win;

	win = get_window();
	SDL_SetRenderDrawColor(win->surface, 255, 255, 255, SDL_ALPHA_OPAQUE);
	SDL_RenderDrawPoint(win->surface, point->x/point->z, point->y/point->z);
}

void	draw_surface_points(t_w3surface *e)
{
	int x;

	x = 0;
	while (x < e->count)
		draw_point(&e->points[x++]);
}

void	draw_surface_lines(t_w3surface *e)
{
	int x;
	SDL_Point *norm1;
	SDL_Point *norm2;

	if (e->count <= 1)
		return ;
	x = 0;
	while (x < e->count)
	{
		if (x > 0)
		{
			norm1 = normilise_point(e->points[x - 1]);
			norm2 = normilise_point(e->points[x]);
			SDL_RenderDrawLine(get_window()->surface, norm1->x, norm1->y, norm2->x, norm2->y);
		}
		x++;
	}
	norm1 = normilise_point(e->points[0]);
	SDL_RenderDrawLine(get_window()->surface, norm1->x, norm1->y, norm2->x, norm2->y);
}