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

SDL_Point	*normilise_point(t_point3 *a)
{
	SDL_Point *ret;

	ret = (SDL_Point *)ft_memalloc(sizeof(SDL_Point));
	ret->x = a->x / (a->z + (a->z == 0));
	ret->y = a->y / (a->z + (a->z == 0));
	return (ret);
}

t_point3	*point3_sum(t_point3 *a, t_point3 *b)
{
	t_point3 *ret;

	ret = make_t_point3(a->x + b->x, a->y + b->y, a->z + b->z);
	return (ret);
}