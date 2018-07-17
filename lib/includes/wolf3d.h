/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgourley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 10:20:49 by wgourley          #+#    #+#             */
/*   Updated: 2018/07/17 11:09:52 by wgourley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLD3D_H
# define WOLD3D_H
# define WINDOW_W 800
# define WINDOW_H 600
#include <mlx.h>
#include <libft.h>
#include <wolf3d.h>

typedef struct	s_window
{
	void	*mlx_pntr;
	void	*window_pntr;
}				t_window;

t_window	*get_window();

#endif