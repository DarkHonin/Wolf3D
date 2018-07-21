/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w3d_surface_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgourley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 23:03:09 by wgourley          #+#    #+#             */
/*   Updated: 2018/07/20 23:03:09 by wgourley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>
#include <w3d_generation.h>

t_point3 **surf_to_point_list(t_w3surface *surf)
{
	return ((t_point3 **)(surf->points->data));
}

void	add_point_to_surface(t_w3surface *s, float x, float y, float z)
{
	t_point3 *r;

	r = make_t_point3(x, y, z);
	vect_push(s->points, &r);
	s->count++;
}