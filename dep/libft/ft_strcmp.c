/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgourley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 16:19:38 by wgourley          #+#    #+#             */
/*   Updated: 2018/05/26 12:55:24 by wgourley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(char const *a, char const *b)
{
	const size_t index = ft_maxi(ft_strlen(a), ft_strlen(b));

	if (!a || !b)
		return (0);
	return (ft_memcmp(a, b, index));
}
