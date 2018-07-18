/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w3d_window.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgourley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 11:04:04 by wgourley          #+#    #+#             */
/*   Updated: 2018/07/17 11:10:14 by wgourley         ###   ########.fr       */
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
	ret->window_pntr = SDL_CreateWindow("Wolf3D", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_W, WINDOW_H, SDL_WINDOW_SHOWN);
	if (!ret->window_pntr)
		w3_std_error("Failed to init window");
	ret->surface = SDL_GetWindowSurface( ret->window_pntr );
	return (ret);
}