/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w3d_space_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgourley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 11:41:59 by wgourley          #+#    #+#             */
/*   Updated: 2018/07/21 11:46:26 by wgourley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

t_w3surface	**get_space_surfaces(t_space *e)
{
	return ((t_w3surface **)e->entities->data);
}

int			get_surface_count(t_space *a)
{
	return (vect_len(a->entities));
}