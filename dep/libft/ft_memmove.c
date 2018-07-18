/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgourley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 20:27:55 by wgourley          #+#    #+#             */
/*   Updated: 2018/05/26 12:52:31 by wgourley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdlib.h>

void	*ft_memmove(void *dest, const void *src, size_t num)
{
	t_byte *in;
	t_byte *out;
	size_t index;

	in = (t_byte *)src;
	out = (t_byte *)dest;
	index = 0;
	while (index < num)
	{
		if (dest < src)
			out[index] = in[index];
		else
			out[num - index - 1] = in[num - index - 1];
		index++;
	}
	return (dest);
}
