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

t_point3	*point3_sum(t_point3 *a, t_point3 *b)
{
	t_point3 *ret;

	ret = make_t_point3(a->cells[0][0] + b->cells[0][0], a->cells[0][1] + b->cells[0][1], a->cells[0][2] + b->cells[0][2]);
	return (ret);
}

float		dst_from_center(t_point3 *e)
{
	return (sqrtf(powf(X(e), 2) + powf(Y(e), 2) + powf(Z(e), 2)));
}