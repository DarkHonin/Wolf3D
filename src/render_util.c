/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgourley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 13:44:34 by wgourley          #+#    #+#             */
/*   Updated: 2018/07/20 14:06:27 by wgourley         ###   ########.fr       */
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

void	draw_surface_lines(t_w3surface *e)
{
	SDL_Point	*points;
	int x;

	x = 0;
	points = (SDL_Point *)ft_memalloc(sizeof(SDL_Point) * (e->count + 1));
	while (x < e->count)
	{
		points[x].x = (e->points[x].x/e->points[x].z);
		points[x].y =  (e->points[x].x/e->points[x].z);
		printf("%i : %i\n", points[x].x, points[x].y);
		x++;
	}
	points[x + 1] = points[0];
	SDL_RenderDrawLines(get_window()->surface, points, e->count);

}