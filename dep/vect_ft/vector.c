/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgourley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 21:42:15 by wgourley          #+#    #+#             */
/*   Updated: 2018/07/06 12:16:42 by wgourley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vect_ft.h"
#include <stdio.h>

void	*vect_pop(t_vector e)
{
	void *ret;
	void *read_pos;

	if (e->buff_size <= 0)
		return (NULL);
	read_pos = (e->data + e->buff_size) - e->meta;
	ret = ft_memalloc(e->meta);
	ft_memcpy(ret, read_pos, e->meta);
	ft_realloc(e->data, e->buff_size, e->buff_size - e->meta);
	e->buff_size -= e->meta;
	return (ret);
}

void	*vect_pull(t_vector e)
{
	void *ret;

	if (e->buff_size <= 0)
		return (NULL);
	ret = ft_memalloc(e->meta);
	ft_memcpy(ret, e->data, e->meta);
	ft_memmove(e->data, e->data + e->meta, e->buff_size - e->meta);
	ft_realloc(e->data, e->buff_size, e->buff_size - e->meta);
	e->buff_size -= e->meta;
	return (ret);
}

void	vect_insert(t_vector e, void *data, int index)
{
	size_t pos;

	pos = e->meta * index;
	ft_realloc(e->data, e->buff_size, e->buff_size + e->meta);
	ft_memmove(e->data + (pos + e->meta), e->data + pos, e->buff_size - pos);
	ft_memcpy(e->data + pos, data, e->meta);
	e->buff_size += e->meta;
}

void	*vect_slice(t_vector e, int index)
{
	void	*ret;
	size_t	pos;

	pos = e->meta * index;
	ret = ft_memalloc(e->meta);
	ft_memcpy(ret, e->data + pos, e->meta);
	ft_memmove(e->data + pos, e->data + pos + e->meta, e->buff_size - pos);
	ft_realloc(e->data, e->buff_size, e->buff_size - e->meta);
	e->buff_size += e->meta;
	return (ret);
}

void	vect_push(t_vector e, void *data)
{
	ft_buffpush(e, data, e->meta);
}
