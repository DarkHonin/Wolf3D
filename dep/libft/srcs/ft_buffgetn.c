/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buffgetn.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgourley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 12:52:20 by wgourley          #+#    #+#             */
/*   Updated: 2018/06/25 16:40:14 by wgourley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**  This version of ft_buffget skips a spesific amount spessified by
**  offset and returns the first object after that
*/

int	ft_buffgetn(size_t get_size, t_buff *buff, void *data, size_t offset)
{
	const size_t skip = get_size * offset;

	buff->pointer = buff->data + skip;
	if (ft_buffstat(buff) < 0)
		return (0);
	ft_memcpy(data, buff->pointer, get_size);
	return (1);
}
