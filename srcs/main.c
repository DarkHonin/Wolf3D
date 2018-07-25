/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgourley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 19:17:03 by wgourley          #+#    #+#             */
/*   Updated: 2018/07/23 19:17:03 by wgourley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>
#include <3d_point.h>

t_window *win;

t_point3 *draw_point(t_point3 *p)
{
	static t_point3 *last = NULL;
	if (last)
		SDL_RenderDrawLine(win->render, X(p), Y(p), X(last), Y(last));
	SDL_RenderDrawPoint(win->render, X(p), Y(p));
	last = p;
	return (p);
}

int main(int av, char **ac)
{
	t_point3_list lst;
	t_point3		*p;

	ft_putstr("Making empty...");
	lst = MAKE_EMPTY_LIST(3);
	lst[0] = MAKE_POINT(10, 20, 20);
	lst[1] = MAKE_POINT(10, 30, 20);
	lst[2] = MAKE_POINT(20, 40, 20);
	ft_putstr("Made\n");
	ft_putstr("Making Window...");
	win = get_window();
	SDL_Event e;
	ft_putstr("Listing map...");
	SDL_SetRenderDrawColor(win->render, 255, 0, 0, 255);
	t_list_map(lst, 3, &draw_point);
	ft_putstr("OK\n");
	while (1)
	{
		while (SDL_PollEvent(&e))
			if (e.type == SDL_QUIT)
				exit(0);
		SDL_RenderPresent(win->render);
	}
}