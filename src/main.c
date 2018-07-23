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
#include <w3d_math.h>

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
	vect_push(space->entities, &surf);
	add_point_to_surface(surf, -25, -25, 1);
	//add_point_to_surface(surf, 0, -5, 20);
	add_point_to_surface(surf, 25, -25, 1);
	//add_point_to_surface(surf, 5, 0, 20);
	add_point_to_surface(surf, 25, 25, 1);
	//add_point_to_surface(surf, 0, 5, 20);
	//add_point_to_surface(surf, -25, 25, 1);
	//add_point_to_surface(surf, -5, 0, 20);
	Z(surf->origen) = 100;

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
				if (event.key.keysym.scancode == SDL_SCANCODE_LEFT)
					rotate_surf(surf, -1, &get_rot_matrix_x);
				if (event.key.keysym.scancode == SDL_SCANCODE_RIGHT)
					rotate_surf(surf, 1, &get_rot_matrix_x);
				if (event.key.keysym.scancode == SDL_SCANCODE_UP)
					rotate_surf(surf, -1, &get_rot_matrix_z);
				if (event.key.keysym.scancode == SDL_SCANCODE_DOWN)
					rotate_surf(surf, 1, &get_rot_matrix_z);
				if (event.key.keysym.scancode == SDL_SCANCODE_W)
					rotate_surf(surf, 1, &get_rot_matrix_y);
				if (event.key.keysym.scancode == SDL_SCANCODE_S)
					rotate_surf(surf, -1, &get_rot_matrix_y);
				clear();
				SDL_SetRenderDrawColor(win->surface, 255, 255, 255, SDL_ALPHA_OPAQUE);
				fill_triangle(surf);
				SDL_RenderPresent(win->surface);
			}
		}
	}
}
