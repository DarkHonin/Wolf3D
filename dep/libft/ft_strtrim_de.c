/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim_de.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgourley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 15:04:07 by wgourley          #+#    #+#             */
/*   Updated: 2018/05/26 10:23:27 by wgourley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim_de(const char *e, int (*is)(int))
{
	unsigned int	start;
	unsigned int	end;
	size_t			len;
	char			*ret;

	if (!e)
		return ((char *)NULL);
	start = 0;
	while (e[start] != '\0' && is(e[start]))
		start++;
	end = 0;
	len = 0;
	while (e[start + len] != '\0')
	{
		if (!is(e[start + len]))
			end = len;
		len++;
	}
	ret = ft_strnew(end + 1);
	if (!ret)
		return ((char *)NULL);
	ret = ft_strncpy(ret, e + start, end + 1);
	return (ret);
}
