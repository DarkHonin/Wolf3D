/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buffnap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgourley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 15:16:35 by wgourley          #+#    #+#             */
/*   Updated: 2018/06/22 17:02:02 by wgourley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
/*
**  buff nap is responsible for appending the contents of
**  one buffer starting from the pointer up to n bytes onto
**  the other returning the destination buffer
**  after modifying its content and size
*/

t_buff	*ft_buffnap(t_buff *dest, t_buff *ap, size_t lim)
{
	void	*data_hold;

	data_hold = ft_memalloc(dest->buff_size + ft_buffstat(ap));
	if (dest->data != NULL)
		ft_memcpy(data_hold, dest->data, dest->buff_size);
	ft_memcpy(data_hold + dest->buff_size, ap->pointer,
				ft_minl(ft_buffstat(ap), lim));
	dest->buff_size = dest->buff_size + ft_minl(ft_buffstat(ap), lim);
	if (dest->data != NULL)
		free(dest->data);
	dest->data = data_hold;
	return (dest);
}
