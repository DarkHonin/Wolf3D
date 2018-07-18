/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgourley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 08:14:09 by wgourley          #+#    #+#             */
/*   Updated: 2018/06/28 08:15:43 by wgourley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *src, size_t srclen, size_t nl)
{
	void *ret;

	ret = ft_memalloc(nl);
	ft_memcpy(ret, src, ft_mini(srclen, nl));
	free(src);
	return (ret);
}