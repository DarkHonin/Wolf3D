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
	SDL_RenderDrawPoint(win->surface, point->x/point->z, point->y/point->z);
}

void	draw_surface_points(t_w3surface *e)
{
	int x;
	t_point3		**nodes;

	nodes = surf_to_point_list(e);
	x = 0;
	ft_putendl("Rendering surface points");
	while (x < e->count)
	{
		ft_putnbr(x);
		ft_putendl(" :Point");
		draw_point(nodes[x++]);
	}
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
		if (x > 0)
		{
			norm1 = normilise_point(point3_sum(nodes[x - 1], e->origen));
			norm2 = normilise_point(point3_sum(nodes[x], e->origen));
			norm1->x += WINDOW_CENTER_X;
			norm1->y += WINDOW_CENTER_Y;
			norm2->x += WINDOW_CENTER_X;
			norm2->y += WINDOW_CENTER_Y;
			ft_putnbr(norm1->x);
			ft_putnbr(norm1->y);
			SDL_RenderDrawLine(get_window()->surface, norm1->x, norm1->y, norm2->x, norm2->y);
		}
		x++;
	}
	norm1 = normilise_point(point3_sum(nodes[0], e->origen));
	norm1->x += WINDOW_CENTER_X;
	norm1->y += WINDOW_CENTER_Y;
	SDL_RenderDrawLine(get_window()->surface, norm1->x, norm1->y, norm2->x, norm2->y);
}

void	draw_t_space(t_space *q, void (*draw)(t_w3surface *))
{
	t_w3surface **kids;
	int max;
	int x;

	kids = get_space_surfaces(q);
	max = get_surface_count(q);
	x = 0;
	while (x < max)
	{
		draw(kids[x]);
		x++;
	}
}