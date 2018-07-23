/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point3_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgourley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 14:13:32 by wgourley          #+#    #+#             */
/*   Updated: 2018/07/20 14:15:31 by wgourley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>
#include <w3d_generation.h>
#include <w3d_math.h>
#include <math.h>

SDL_Point	*normilise_point(t_point3 *a)
{
	SDL_Point *ret;

	ret = (SDL_Point *)ft_memalloc(sizeof(SDL_Point));
	ret->x = a->cells[0][0] / ((Z(a) + (Z(a) == 0)) / 255);
	ret->y = a->cells[0][1] / ((Z(a) + (Z(a) == 0)) / 255);
	ret->x += WINDOW_CENTER_X;
	ret->y += WINDOW_CENTER_Y;
	return (ret);
}

SDL_Point	**normilise_point_list(t_point3 **a, int amount)
{
	int			x;
	SDL_Point	**ret;

	ret = (SDL_Point **)ft_memalloc(sizeof(SDL_Point *) * amount);
	x = 0;
	while (x < amount)
	{
		ret[x] = normilise_point(a[x]);
		x++;
	}
	return (ret);
}

float		dst_from_center(t_point3 *e)
{
	return (sqrtf(powf(X(e), 2) + powf(Y(e), 2) + powf(Z(e), 2)));
}

float		point3_dist(t_point3 *a, t_point3 *b)
{
	return (abs(sqrtf(powf(X(a) - X(b), 2) + powf(Y(a) - Y(b), 2) + powf(Z(a) - Z(b), 2))));
}

float		point3_direction(t_point3 *a, t_point3 *b)
{

}

t_shape		points_to_shape(t_point3 **pnts, int count)
{
	int x;
	t_shape ret;

	ret = (t_shape)ft_memalloc(sizeof(t_line *) * count);
	while (x < count)
	{
		if (x == 0)
			ret[x] = pnts_to_line(pnts[x], pnts[count - 1]);
		else
			ret[x] = pnts_to_line(pnts[x], pnts[x - 1]);
		x++;
	}
	return (ret);
}