/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   factory.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgourley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 22:38:28 by wgourley          #+#    #+#             */
/*   Updated: 2018/07/20 22:38:28 by wgourley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <w3d_generation.h>

t_space			*make_t_space()
{
	t_space *ret;

	ret = (t_space *)ft_memalloc(sizeof(t_space));
	ret->entities = MAKE_VECT(sizeof(t_w3surface *));
	return (ret);
}

t_point3		*make_t_point3(float x, float y, float z)
{
	t_point3	*ret;

	ret = (t_point3 *)ft_memalloc(sizeof(t_point3));
	ret->x = x;
	ret->y = y;
	ret->z = z;
	return (ret);
}

t_w3surface		*make_t_w3surface()
{
	t_w3surface *ret;

	ret = (t_w3surface *)ft_memalloc(sizeof(t_w3surface));
	ret->points = MAKE_VECT(sizeof(t_point3 *));
	ret->count = 0;
	return (ret);
}