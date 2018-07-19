/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgourley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 17:58:52 by wgourley          #+#    #+#             */
/*   Updated: 2018/07/17 17:58:52 by wgourley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

int main(int ac, char *av[])
{
	t_window *win = get_window();
	SDL_Event event;
	int running = 1;

	while(running)
	{
		while (SDL_PollEvent(&event) != 0)
		{
			if (event.type == SDL_QUIT)
				running = 0;
			if (event.type == SDL_KEYDOWN)
				if (event.key.keysym.scancode == 41)
					running = 0;
		}
		SDL_UpdateWindowSurface(win->window_pntr);
	}
}
