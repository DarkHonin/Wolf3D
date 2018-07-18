/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgourley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 00:29:07 by wgourley          #+#    #+#             */
/*   Updated: 2018/06/12 10:39:45 by wgourley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strnstr(char const *big, char const *little, size_t max)
{
	size_t	internal;
	size_t	index;

	if (!ft_strlen(big))
		return ((char *)NULL);
	if (!ft_strlen(little))
		return ((char *)(big));
	index = 0;
	internal = 0;
	while (index < max && big[index])
	{
		if (little[internal] != big[index])
		{
			index = index - internal;
			internal = 0;
		}
		else if (little[internal + 1] == '\0')
			return ((char *)big + index - internal);
		else
			internal++;
		index++;
	}
	return ((char *)NULL);
}
