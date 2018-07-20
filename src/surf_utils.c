/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   surf_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgourley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 23:59:02 by wgourley          #+#    #+#             */
/*   Updated: 2018/07/20 23:59:02 by wgourley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

void	add_point_to_surface(t_w3surface *s, t_point3 **p)
{
	vect_push(s->points, p);
}