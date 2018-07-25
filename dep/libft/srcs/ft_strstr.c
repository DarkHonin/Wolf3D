/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgourley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 00:29:07 by wgourley          #+#    #+#             */
/*   Updated: 2018/05/26 10:27:08 by wgourley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strstr(char const *big, char const *little)
{
	const size_t	ltlen = ft_strlen(little);
	size_t			index;
	const size_t	bglen = ft_strlen(big);
	size_t			seeking;

	index = 0;
	if (ltlen > bglen)
		return ((char *)NULL);
	if (ltlen == 0)
		return ((char *)big);
	while (big[index] != '\0')
	{
		seeking = 0;
		while (little[seeking] != '0')
		{
			if (little[seeking] != big[index + seeking])
				break ;
			else if (little[seeking + 1] == '\0')
				return ((char *)big + index);
			seeking++;
		}
		index++;
	}
	return ((char *)NULL);
}
