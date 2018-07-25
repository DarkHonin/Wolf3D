/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgourley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 16:10:25 by wgourley          #+#    #+#             */
/*   Updated: 2018/05/22 10:45:27 by wgourley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strncpy(char *dest, const char *src, size_t max)
{
	size_t index;

	ft_bzero(dest, max);
	index = 0;
	while (index < max)
	{
		dest[index] = src[index];
		if (src[index] == '\0')
			return (dest);
		index++;
	}
	if (index == max - 1)
		dest[index] = '\0';
	return (dest);
}
