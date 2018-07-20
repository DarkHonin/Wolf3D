/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgourley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 17:58:52 by wgourley          #+#    #+#             */
/*   Updated: 2018/07/20 14:19:32 by wgourley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>
#include <w3d_generation.h>

int main(int ac, char *av[])
{
	t_window *win = get_window();
	SDL_Event event;
	int running = 1;
	clear();

	t_space *space;
	t_w3surface *surf;
	t_point3	*pnt;

	space = make_t_space();
	surf = make_t_w3surface();
	pnt = make_t_point3(50, 50, 1);
	vect_push(surf->points, &pnt);
	pnt = make_t_point3(75, 70, 1.1);
	vect_push(surf->points, &pnt);
	pnt = make_t_point3(100, 50, 1);
	vect_push(surf->points, &pnt);
	pnt = make_t_point3(80, 75, 1.1);
	vect_push(surf->points, &pnt);
	pnt = make_t_point3(100, 100, 1);
	vect_push(surf->points, &pnt);
	pnt = make_t_point3(75, 80, 1.1);
	vect_push(surf->points, &pnt);

	pnt = make_t_point3(50, 100, 1);
	vect_push(surf->points, &pnt);

	pnt = make_t_point3(70, 75, 1.1);
	vect_push(surf->points, &pnt);
	vect_push(space->entities, &surf);
	surf->count = 8;

	clear();
	SDL_SetRenderDrawColor(win->surface, 255, 255, 255, SDL_ALPHA_OPAQUE);
	draw_surface_lines(surf);
	SDL_RenderPresent(win->surface);
	while(running)
	{
		while (SDL_PollEvent(&event) != 0)
		{
			if (event.type == SDL_QUIT)
				running = 0;
			if (event.type == SDL_KEYDOWN)
			{
				if (event.key.keysym.scancode == 41)
					running = 0;
				clear();
				SDL_SetRenderDrawColor(win->surface, 255, 255, 255, SDL_ALPHA_OPAQUE);
				draw_surface_lines(surf);
				SDL_RenderPresent(win->surface);
			}
		}
	}
}
