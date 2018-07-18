/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgourley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 00:21:15 by wgourley          #+#    #+#             */
/*   Updated: 2018/05/26 13:00:38 by wgourley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strchr(char const *hay, int needle)
{
	char	*ret;
	size_t	max;

	max = ft_strlen(hay) + 1;
	ret = (char *)ft_memchr(hay, needle, max);
	return (ret);
}
