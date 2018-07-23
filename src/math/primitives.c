/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   primitives.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgourley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 10:59:15 by wgourley          #+#    #+#             */
/*   Updated: 2018/07/22 10:59:15 by wgourley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <w3d_math.h>

t_line	*pnts_to_line(t_point3 *a, t_point3 *b)
{
	t_line *ret;

	ret = (t_line *)ft_memalloc(sizeof(t_line));
	ret->a = a;
	ret->b = b;
	ret->distance = sqrtf(powf(X(a) - X(b), 2) + powf(Y(a) - Y(b), 2) + powf(Z(a) - Z(b), 2));
	return (ret);
}