/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr_f.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgourley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 17:03:45 by wgourley          #+#    #+#             */
/*   Updated: 2018/06/13 10:20:56 by wgourley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr_f(const void *hay, int (*f)(int), size_t len)
{
	size_t			index;
	unsigned char	*in;

	in = (unsigned char *)hay;
	index = 0;
	while (index < len)
	{
		if (f((int)in[index]))
			return ((void *)hay + index);
		index++;
	}
	return ((void *)NULL);
}
