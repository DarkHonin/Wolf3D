/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgourley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 00:08:48 by wgourley          #+#    #+#             */
/*   Updated: 2018/05/26 13:02:13 by wgourley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

size_t	ft_strlcat(char *dest, char const *src, size_t max)
{
	size_t		dstlen;
	size_t		index;

	dstlen = ft_strlen(dest);
	index = 0;
	if (dstlen >= max)
		return (max + ft_strlen(src));
	while (index + dstlen < max - 1 && src[index])
	{
		dest[dstlen + index] = src[index];
		index++;
	}
	dest[index + dstlen] = '\0';
	return (dstlen + ft_strlen(src));
}
