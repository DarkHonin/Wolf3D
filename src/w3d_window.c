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
	ret->mlx_pntr = mlx_init();
	if (!ret->mlx_pntr)
		w3_std_error("Failed to init grapics");
	ret->window_pntr = mlx_new_window(ret->mlx_pntr, WINDOW_W, WINDOW_H, "Wolf3D");
	if (!ret->window_pntr)
		w3_std_error("Failed to init window");
	return (ret);
}