/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgourley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 21:07:29 by wgourley          #+#    #+#             */
/*   Updated: 2018/06/13 10:20:36 by wgourley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memccmp(const void *one, const void *two, char stp, size_t len)
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
		if (a == stp && b == stp)
			break ;
		index++;
	}
	return (0);
}
