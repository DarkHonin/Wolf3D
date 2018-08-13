/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgourley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 15:13:41 by wgourley          #+#    #+#             */
/*   Updated: 2018/08/13 15:55:38 by wgourley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>
#include <math.h>

int	ray(float angle, t_player p, t_map *m)
{
	float		rad;
	int			dst;
	t_value_v	v;
	t_value_v	pv;

	v = create_value_v(2);
	pv = create_value_v(2);
	rad = (angle / 180) * M_PI;
	pv[0] = p[0] * m->size[0];
	pv[1] = p[1] * m->size[1];
	dst = 0;
	while (dst < VIEW_MAX)
	{
		dst++;
	}
	return (0);
}

void	trace()
{
	t_player	player;
	t_map		*map;
	float		t;
	float		v;
	float		ev;

	player = get_player();
	map = get_map();
	t = player[2] - (FOV / 2);
	v = 0;
	while (v < FOV / 2)
	{
		if ((int)v % 2 == 0)
			ev = t + v;
		else
			ev = (t + FOV) - v;
		if (ray(ev, player, map))
			break ;
		v++;
	}
}