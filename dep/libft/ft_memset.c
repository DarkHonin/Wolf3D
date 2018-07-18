/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgourley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 19:27:44 by wgourley          #+#    #+#             */
/*   Updated: 2018/05/20 12:59:04 by wgourley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dest, int sub, int len)
{
	unsigned char	*rp;
	int				index;

	index = 0;
	rp = (unsigned char *)dest;
	while (index < len)
	{
		rp[index] = sub;
		index++;
	}
	return (rp);
}
