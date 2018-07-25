/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgourley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 07:52:46 by wgourley          #+#    #+#             */
/*   Updated: 2018/05/26 13:02:39 by wgourley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strmapi(char const *srt, char (*f)(unsigned int, char))
{
	char	*ret;
	size_t	len;
	size_t	pos;

	if (!srt || !f)
		return ((char *)NULL);
	pos = 0;
	len = ft_strlen(srt);
	ret = (char *)ft_memalloc(len + 1);
	if (!ret)
		return ((char *)NULL);
	while (srt[pos] != '\0')
	{
		ret[pos] = f(pos, srt[pos]);
		pos++;
	}
	return (ret);
}
