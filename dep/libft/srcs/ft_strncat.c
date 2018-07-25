/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgourley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 20:20:51 by wgourley          #+#    #+#             */
/*   Updated: 2018/05/26 13:03:22 by wgourley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t max)
{
	size_t len;
	size_t index;

	len = ft_strlen(dest);
	index = 0;
	while (src[index] && index < max)
	{
		dest[len + index] = src[index];
		index++;
	}
	dest[index + len] = '\0';
	return (dest);
}
