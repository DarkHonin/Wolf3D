/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgourley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 17:58:52 by wgourley          #+#    #+#             */
/*   Updated: 2018/07/21 11:48:39 by wgourley         ###   ########.fr       */
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
	surf->origen->x = -50;
	surf->origen->y = -50;
	surf->origen->z = 0.5;
	pnt = make_t_point3(50, 50, 1);
	vect_push(surf->points, &pnt);
	pnt = make_t_point3(75, 70, 1.01);
	vect_push(surf->points, &pnt);
	pnt = make_t_point3(100, 50, 1);
	vect_push(surf->points, &pnt);
	pnt = make_t_point3(80, 75, 1.01);
	vect_push(surf->points, &pnt);
	pnt = make_t_point3(100, 100, 1);
	vect_push(surf->points, &pnt);
	pnt = make_t_point3(75, 80, 1.01);
	vect_push(surf->points, &pnt);

	pnt = make_t_point3(50, 100, 1);
	vect_push(surf->points, &pnt);

	pnt = make_t_point3(70, 75, 1.01);
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
				if (event.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
					running = 0;
				if (event.key.keysym.scancode == SDL_SCANCODE_UP)
					surf->origen->y++;
				if (event.key.keysym.scancode == SDL_SCANCODE_DOWN)
					surf->origen->y--;
				if (event.key.keysym.scancode == SDL_SCANCODE_LEFT)
					surf->origen->x--;
				if (event.key.keysym.scancode == SDL_SCANCODE_RIGHT)
					surf->origen->x++;
				if (event.key.keysym.scancode == SDL_SCANCODE_KP_PLUS)
					surf->origen->z*=0.9;
				if (event.key.keysym.scancode == SDL_SCANCODE_KP_MINUS)
					surf->origen->z/=0.9;
				clear();
				SDL_SetRenderDrawColor(win->surface, 255, 255, 255, SDL_ALPHA_OPAQUE);
				draw_t_space(space, &draw_surface_lines);
				SDL_RenderPresent(win->surface);
			}
		}
	}
}
