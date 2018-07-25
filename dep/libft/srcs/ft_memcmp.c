/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgourley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 21:07:29 by wgourley          #+#    #+#             */
/*   Updated: 2018/06/13 10:21:37 by wgourley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *one, const void *two, size_t len)
{
	size_t	index;
	t_byte	a;
	t_byte	b;

	index = 0;
	while (index < len)
	{
		a = ((t_byte *)one)[index];
		b = ((t_byte *)two)[index];
		if (a != b)
			return (a - b);
		index++;
	}
	return (0);
}
