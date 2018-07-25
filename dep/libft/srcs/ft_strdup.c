/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgourley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 17:28:02 by wgourley          #+#    #+#             */
/*   Updated: 2018/05/26 13:00:57 by wgourley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *src)
{
	int		len;
	char	*buffer;

	len = ft_strlen(src);
	buffer = (char *)ft_memalloc(sizeof(char) * (len + 1));
	if (buffer == (char *)NULL)
		return ((char *)NULL);
	ft_memcpy(buffer, src, len + 1);
	buffer[len] = '\0';
	return (buffer);
}
