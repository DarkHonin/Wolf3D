/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr_n.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgourley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 17:19:07 by wgourley          #+#    #+#             */
/*   Updated: 2018/05/26 12:48:23 by wgourley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strchr_n(char const *hay, int needle)
{
	char	*ret;
	size_t	max;

	max = ft_strlen(hay) + 1;
	ret = (char *)ft_memchr_n(hay, needle, max);
	return (ret);
}
