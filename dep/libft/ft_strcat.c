/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgourley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 16:24:53 by wgourley          #+#    #+#             */
/*   Updated: 2018/05/20 12:10:59 by wgourley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

char	*ft_strcat(char *a, const char *b)
{
	size_t	size_a;
	size_t	size_b;

	size_a = ft_strlen(a);
	size_b = ft_strlen(b);
	ft_memcpy(a + size_a, b, size_b);
	a[size_a + size_b] = '\0';
	return (a);
}
