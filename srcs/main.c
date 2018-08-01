/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgourley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/30 17:33:59 by wgourley          #+#    #+#             */
/*   Updated: 2018/08/01 12:21:06 by wgourley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>
#include <stdio.h>
static void draw_point(t_point3 a)
{
	t_projected_point *q = standard_projection(&a);

	put_pixel(X(q) + WINDOW_C_W, Y(q) + WINDOW_C_H, 255, ((10 - Z((&a))) / 10) * 255, 0);
}

static void draw_line(t_line a)
{
	plot_line(a, 0.5, &draw_point);
}

int loop(void *e)
{
	static t_line *lines = NULL;
	t_mesh *mesh;

	mesh = e;
	if (!lines)
	{
		lines = list_to_lines(mesh->points[0], 5, mesh->origen);
		ft_putendl("lines derrived\n");
	}
	line_itter(lines, mesh->size[0], &draw_line);
	
	flip();
	return (1);
}

int main(void)
{
	get_window();

	t_size size = MAKE_SIZE(1, 5);
	t_point3_surface surf = MAKE_EMPTY_SURFACE(size);
	//set_point(surf[0], -WINDOW_C_W, 0, 0);
	//set_surf_point(surf, MAKE_SIZE(0, 0), -WINDOW_C_W, 0, 0);
	//set_surf_point(surf, MAKE_SIZE(1, 0), -WINDOW_C_W / 2, 0, 10);
	//set_surf_point(surf, MAKE_SIZE(2, 0), 0, 0, 10);
	//set_surf_point(surf, MAKE_SIZE(3, 0), WINDOW_C_W / 2, 0, 10);
	//set_surf_point(surf, MAKE_SIZE(4, 0), WINDOW_C_W, 0, 10);
	ft_putendl("Points assigned");
	t_mesh	*mesh = make_mesh(surf, size, MAKE_POINT(0, 0, 1));
	ft_putendl("Init complete");
	start_loop(&loop, mesh);
}