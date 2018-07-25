/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgourley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 08:40:57 by wgourley          #+#    #+#             */
/*   Updated: 2018/05/26 12:47:20 by wgourley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strmap(char const *srt, char (*f)(char))
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
		ret[pos] = f(srt[pos]);
		pos++;
	}
	return (ret);
}
