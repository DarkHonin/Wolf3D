/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgourley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 21:18:50 by wgourley          #+#    #+#             */
/*   Updated: 2018/07/12 14:17:30 by wgourley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vect_ft.h"

void	vect_dump(t_vector e)
{
	int					in;
	const unsigned char *dump = e->data;

	in = 0;
	while (in < (e->buff_size))
	{
		if (in % 16 == 0)
			ft_putendl("|");
		ft_putstr(ft_itoa_b(dump[in], 16));
		ft_putstr(" ");
		in++;
	}
	ft_putendl("");
}

void	*vect_get_shallow(t_vector e, int index)
{
	void	*ret;
	size_t	pos;

	pos = e->meta * index;
	ret = e->data + pos;
	return (ret);
}

void	*vect_get_next(t_vector e)
{
	void *ret;

	if (ft_buffstat(e) < e->meta)
		return (NULL);
	ret = e->pointer;
	e->pointer += e->meta;
	return (ret);
}

void	vect_itter(t_vector e, void (*f)(t_vector, void *))
{
	void *a;

	ft_buffreset(e);
	while ((a = vect_get_next(e)))
		f(e, a);
}

void	*vect_get(t_vector e, int index)
{
	void	*ret;
	size_t	pos;

	pos = e->meta * index;
	ret = ft_memalloc(e->meta);
	ft_memcpy(ret, e->data + pos, e->meta);
	return (ret);
}
