/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgourley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 17:24:48 by wgourley          #+#    #+#             */
/*   Updated: 2018/06/07 12:59:49 by wgourley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strndup(const char *src, size_t max)
{
	int		len;
	char	*buffer;

	len = ft_mini(ft_strlen(src), max);
	buffer = (char *)ft_memalloc(sizeof(char) * (len + 1));
	if (buffer == (char *)NULL)
		return ((char *)NULL);
	ft_memcpy(buffer, src, len + 1);
	buffer[len] = '\0';
	return (buffer);
}
