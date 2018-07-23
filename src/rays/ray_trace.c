/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_trace.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgourley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 14:37:12 by wgourley          #+#    #+#             */
/*   Updated: 2018/07/22 14:37:13 by wgourley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>
#include <w3d_generation.h>
#include <w3d_math.h>

void	trace(t_space *e)
{
	int 		x;
	int 		y;
	t_line		*ray;
	t_point3	*a;
	t_point3	*b;
	x = 0;
	while (x < WINDOW_W)
	{
		y = 0;
		while (y < WINDOW_H)
		{
			a = make_t_point3(x, y, 0);
			b = make_t_point3(x, y, 255);
			ray = pnts_to_line(a, b);
			y++;
		}
		x++;
	}
}

void	collides_surface(t_w3surface *a, t_line *pnt)
{
	t_point3 **normed;

	normed = get_surf_points(a);

}