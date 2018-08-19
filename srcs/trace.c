/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgourley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 15:13:41 by wgourley          #+#    #+#             */
/*   Updated: 2018/08/19 12:04:37 by wgourley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>
#include <math.h>

t_value				mu(t_value in, t_value v)
{
	return (in * v);
}

static t_value_v	ray(t_value angle, t_player p, t_map *m)
{
	t_value		rad;
	t_value		dst;
	t_value_v	v;
	t_value_v	pv;

	v = create_value_v(4);
	pv = clone_value_v(p, 2);
	rad = (angle / 180) * M_PI;
	apply_value(pv, m->size[0], 2, &mu);
	dst = 0;
	while (dst < VIEW_MAX)
	{
		v[0] = (((dst / VIEW_MAX) * m->size[0]) * cos(rad)) + pv[0];
		v[1] = (((dst / VIEW_MAX) * m->size[1]) * sin(rad)) + pv[1];
		if (v[0] < m->size[0] && v[1] < m->size[1] && v[0] > 0 && v[1] > 0)
			if (m->points[(int)v[0] + ((int)v[1] * m->size[1])] > 0)
			{
				v[3] = m->points[(int)v[0] + ((int)v[1] * m->size[1])];
				break ;
			}
		dst += 0.1;
	}
	v[2] = dst;
	free(pv);
	return (v);
}

static t_value		get_point_angle(t_value_v p)
{
	t_value	x;
	t_value y;
	t_value t;

	x = p[0] - (int)p[0] - 0.5;
	y = p[1] - (int)p[1] - 0.5;
	t = atan2(y, x);
	if (t <= 0)
		t += 2 * M_PI;
	t *= 180 / M_PI;
	t += 45;
	t = (int)t % 360;
	return (t);
}

void				touch(t_value angle, t_player p, t_map *m)
{
	t_value_v			pp;
	t_value_v			last;
	t_value				ra;
	t_value				cang;
	t_color				c;

	ra = (p[2] - (FOV / 2)) + angle;
	pp = ray(ra, p, m);

	cang = get_point_angle(pp);
	cang /= 90;
	cang = (int)cang;
	c[0] = (255 * (cang / 3)) * ((VIEW_MAX - pp[2]) / VIEW_MAX);
	c[1] = (255 * (cang / 3)) * ((VIEW_MAX - pp[2]) / VIEW_MAX);
	c[2] = (255 * ((3 - cang) / 3)) * ((VIEW_MAX - pp[2]) / VIEW_MAX);
	pp[0] = (angle / FOV) * WINDOW_W;
	last = clone_value_v(pp, 2);
	pp[1] = WINDOW_C_H + pow(((VIEW_MAX - pp[2]) / VIEW_MAX)
											* WINDOW_C_H, 0.9);
	last[1] = WINDOW_C_H - pow(((VIEW_MAX - pp[2]) / VIEW_MAX)
											* WINDOW_C_H, 0.9);
	draw_line(pp, last, 2, c);
	free(pp);
	free(last);
}

void				trace(void)
{
	t_player	player;
	t_map		*map;
	t_value		v;
	t_value		ev;

	player = get_player();
	map = get_map(NULL);
	v = 0;
	while (v <= FOV)
	{
		if ((int)v % 2 == 0)
			ev = v;
		else
			ev = FOV - v;
		touch(ev, player, map);
		v += 0.01;
	}
}
