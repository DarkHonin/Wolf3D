/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgourley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 00:26:01 by wgourley          #+#    #+#             */
/*   Updated: 2018/05/26 12:56:10 by wgourley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strrchr(char const *hay, int needle)
{
	size_t	offset;
	size_t	len;
	char	*last;

	len = ft_strlen(hay);
	last = (char *)NULL;
	offset = 0;
	while (hay[offset] != '\0' && offset < len)
	{
		if (hay[offset] == needle)
			last = (char *)hay + offset;
		offset++;
	}
	if (hay[offset] == needle)
		last = (char *)hay + offset;
	return (last);
}
