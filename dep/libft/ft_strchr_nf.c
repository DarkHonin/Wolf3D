/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr_nf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgourley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 17:12:45 by wgourley          #+#    #+#             */
/*   Updated: 2018/05/26 12:56:24 by wgourley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strchr_nf(char const *hay, int (*f)(int))
{
	char	*ret;
	size_t	max;

	max = ft_strlen(hay) + 1;
	ret = (char *)ft_memchr_nf(hay, f, max);
	return (ret);
}
