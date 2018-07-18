/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr_n.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgourley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 17:17:39 by wgourley          #+#    #+#             */
/*   Updated: 2018/06/13 10:21:26 by wgourley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr_n(const void *hay, int needle, size_t len)
{
	size_t			index;
	unsigned char	*in;

	in = (unsigned char *)hay;
	index = 0;
	while (index < len)
	{
		if (in[index] != (unsigned char)needle)
			return ((void *)hay + index);
		index++;
	}
	return ((void *)NULL);
}
