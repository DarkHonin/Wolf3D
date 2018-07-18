/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim_delim.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgourley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 15:03:34 by wgourley          #+#    #+#             */
/*   Updated: 2018/05/26 10:22:56 by wgourley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim_delim(const char *e, char a)
{
	unsigned int	start;
	unsigned int	end;
	size_t			len;
	char			*ret;

	if (!e)
		return ((char *)NULL);
	start = 0;
	while (e[start] != '\0' && ft_ischr(e[start], a))
		start++;
	end = 0;
	len = 0;
	while (e[start + len] != '\0')
	{
		if (!ft_ischr(e[start + len], a))
			end = len;
		len++;
	}
	ret = ft_strnew(end + 1);
	if (!ret)
		return ((char *)NULL);
	ret = ft_strncpy(ret, e + start, end + 1);
	return (ret);
}
