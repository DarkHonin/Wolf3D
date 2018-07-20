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
			norm1 = normilise_point(nodes[x - 1]);
			norm2 = normilise_point(nodes[x]);
			ft_putendl("Rendering surface points");
			ft_putnbr(norm1->x);
			ft_putstr(" : ");
			ft_putnbr(norm1->y);
			ft_putendl("");
			SDL_RenderDrawLine(get_window()->surface, norm1->x, norm1->y, norm2->x, norm2->y);
		}
		x++;
	}
	norm1 = normilise_point(nodes[0]);
	SDL_RenderDrawLine(get_window()->surface, norm1->x, norm1->y, norm2->x, norm2->y);
}