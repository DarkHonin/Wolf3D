/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr_f.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgourley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 17:02:15 by wgourley          #+#    #+#             */
/*   Updated: 2018/05/26 12:58:12 by wgourley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strchr_f(char const *hay, int (*f)(int))
{
	char	*ret;
	size_t	max;

	max = ft_strlen(hay) + 1;
	ret = (char *)ft_memchr_f(hay, f, max);
	return (ret);
}
