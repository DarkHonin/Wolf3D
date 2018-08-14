/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgourley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 15:13:41 by wgourley          #+#    #+#             */
/*   Updated: 2018/08/14 15:02:58 by wgourley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>
#include <math.h>
#include <stdio.h>

t_value_v	ray(float angle, t_player p, t_map *m)
{
	float		rad;
	float		dst;
	t_value_v	v;
	t_value_v	pv;

	v = create_value_v(4);
	pv = create_value_v(2);
	rad = (angle / 180) * M_PI;
	pv[0] = p[0] * m->size[0];
	pv[1] = p[1] * m->size[1];
	dst = 0;
	while (dst < VIEW_MAX)
	{
		v[0] = ((dst / VIEW_MAX) * m->size[0]) * cos(rad);
		v[1] = ((dst / VIEW_MAX) * m->size[1]) * sin(rad);
		v[0] += pv[0];
		v[1] += pv[1];
		if (v[0] < m->size[0] && v[1] < m->size[1] && v[0] > 0 && v[1] > 0)
			if (m->points[(int)v[0] + ((int)v[1] * m->size[1])] > 0)
			{
				v[3] = m->points[(int)v[0] + ((int)v[1] * m->size[1])];
				break ;
			}
		put_pixel(v[0] * MINI_SIZE, v[1] * MINI_SIZE, 100, 255, 100);
		dst++;
	}
	v[2] = dst;
	return (v);
}

void	touch(float angle, t_player p, t_map *m)
{
	t_value_v			pp;
	t_value_v			last = NULL;
	float				ra;
	t_color				c;

	ra = (p[2] - (FOV / 2)) + angle;
	pp = ray(ra, p, m);
	if (pp[2] >= VIEW_MAX)
		return ;
	c[0] = (pp[2] / VIEW_MAX) * 255;
	c[1] = 0;
	c[2] = 0;
	if (pp[3] == 1)
		c[0] = 255;
	pp[0] = (angle / FOV) * WINDOW_W;

	last = clone_value_v(pp, 2);

	pp[1] = WINDOW_C_H + (((VIEW_MAX - pp[2]) / VIEW_MAX) * WINDOW_C_H);
	last[1] = WINDOW_C_H - (((VIEW_MAX - pp[2]) / VIEW_MAX) * WINDOW_C_H);
	draw_line(pp, last, 2, c);
	free(pp);
	free(last);
	
}

void	trace()
{
	t_player	player;
	t_map		*map;
	float		v;
	float		ev;

	player = get_player();
	map = get_map();
	v = 0;
	while (v <= FOV)
	{
		if ((int)v % 2 == 0)
			ev = v;
		else
			ev = FOV - v;
		touch(ev, player, map);
		v+=0.05;
	}
}