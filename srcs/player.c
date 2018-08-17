/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgourley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 10:43:08 by wgourley          #+#    #+#             */
/*   Updated: 2018/08/17 14:11:50 by wgourley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>
#include <math.h>

t_player	get_player(void)
{
	static t_player p = NULL;

	if (p)
		return (p);
	p = create_value_v(3);
	p[0] = 0.5;
	p[1] = 0.5;
	p[2] = -90;
	return (p);
}

void		draw_player(void)
{
	t_player	p;
	t_value_m	d;
	t_map		*map;
	float		t;
	t_size		s;

	p = get_player();
	s[0] = 2;
	s[1] = 3;
	d = create_value_m(s);
	map = get_map(NULL);
	d[0][0] = MINI_SIZE * p[0] * map->size[0];
	d[0][1] = MINI_SIZE * p[1] * map->size[1];
	t = ((p[2] - (FOV / 2)) / 180) * M_PI;
	d[1][0] = (cos(t) * VIEW_MAX) + d[0][0];
	d[1][1] = (sin(t) * VIEW_MAX) + d[0][1];
	t = ((p[2] + (FOV / 2)) / 180) * M_PI;
	d[2][0] = (cos(t) * VIEW_MAX) + d[0][0];
	d[2][1] = (sin(t) * VIEW_MAX) + d[0][1];
	draw_line(d[0], d[1], 2, (t_color){255, 0, 0});
	draw_line(d[0], d[2], 2, (t_color){255, 0, 0});
	put_pixel(d[0][0], d[0][1], (t_color){255, 255, 255});
	free_value_m(d, 3);
}
