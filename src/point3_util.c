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

SDL_Point	*normilise_point(t_point3 a)
{
	SDL_Point *ret;

	ret = (SDL_Point *)ft_memalloc(sizeof(SDL_Point));
	ret->x = a.x / a.z;
	ret->y = a.y / a.z;
	return (ret);
}