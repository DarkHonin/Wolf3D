/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgourley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 08:11:34 by wgourley          #+#    #+#             */
/*   Updated: 2018/05/23 08:16:24 by wgourley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(const char *src, unsigned int start, size_t len)
{
	char *ret;

	if (!src)
		return ((char *)NULL);
	ret = (char *)ft_memalloc(len + 1);
	if (!ret)
		return ((char *)NULL);
	ft_strncpy(ret, src + start, len);
	return (ret);
}
