/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgourley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 16:35:12 by wgourley          #+#    #+#             */
/*   Updated: 2018/05/20 13:02:06 by wgourley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	*ft_memcpy(void *dest, const void *src, size_t len)
{
	size_t			zero;
	unsigned char	*srcc;
	unsigned char	*dess;

	srcc = (unsigned char *)src;
	dess = (unsigned char *)dest;
	zero = 0;
	while (zero < len)
	{
		dess[zero] = srcc[zero];
		zero++;
	}
	return (dest);
}
