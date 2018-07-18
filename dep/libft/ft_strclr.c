/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgourley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 08:18:09 by wgourley          #+#    #+#             */
/*   Updated: 2018/05/28 06:20:36 by wgourley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	ft_strclr(char *src)
{
	size_t len;

	if (!src)
		return ;
	len = ft_strlen(src);
	ft_bzero(src, len);
}
