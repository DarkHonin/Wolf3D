/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w3d_window.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgourley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 11:04:04 by wgourley          #+#    #+#             */
/*   Updated: 2018/07/20 13:49:33 by wgourley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>
#include <wolf3d_err.h>

t_window	*get_window()
{
	static t_window *ret = NULL;

	if (ret)
		return (ret);
	ret = (t_window *)ft_memalloc(sizeof(t_window));
	ret->init = SDL_Init(SDL_INIT_VIDEO);
	ft_putendl("Init SDL");
	if (ret->init < 0)
		w3_std_error("Failed to init grapics");
	if (SDL_CreateWindowAndRenderer( WINDOW_W, WINDOW_H, 0,&ret->window_pntr, &ret->surface) != 0)
		w3_std_error("Failed to init window");
	return (ret);
}

void		clear()
{
	t_window *win;

	win = get_window();
	SDL_SetRenderDrawColor(win->surface, 0, 0, 0, SDL_ALPHA_OPAQUE);
	SDL_RenderClear(win->surface);
}