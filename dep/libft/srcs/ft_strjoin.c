/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgourley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 08:19:18 by wgourley          #+#    #+#             */
/*   Updated: 2018/05/26 12:46:03 by wgourley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *a, const char *b)
{
	char	*ret;
	size_t	tlen;

	if (!a || !b)
		return ((char *)NULL);
	tlen = ft_strlen(a) + ft_strlen(b);
	ret = (char *)ft_memalloc(sizeof(char *) * tlen + 1);
	if (!ret)
		return ((char *)NULL);
	ft_strcat(ret, a);
	ft_strcat(ret, b);
	return (ret);
}
