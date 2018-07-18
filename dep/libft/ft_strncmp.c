/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgourley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 16:26:14 by wgourley          #+#    #+#             */
/*   Updated: 2018/05/26 13:05:59 by wgourley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

int	ft_strncmp(char const *a, char const *b, size_t lim)
{
	size_t index;

	index = ft_maxi(ft_strlen(a), ft_strlen(b));
	index = ft_mini(lim, index);
	return (ft_memccmp(a, b, '\0', lim));
}
