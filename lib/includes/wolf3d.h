/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgourley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/26 00:30:22 by wgourley          #+#    #+#             */
/*   Updated: 2018/07/26 00:30:22 by wgourley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H
# include <SDL2/SDL.h>
# include <3d_point.h>

typedef struct	s_win
{
	int			init;
	SDL_Window	*window_pntr;
	SDL_Renderer	*render;
}				t_window;

# define WINDOW_H 600
# define WINDOW_W 800

t_window	*get_window();
void		clear();

#endif