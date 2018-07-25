/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgourley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 21:00:52 by wgourley          #+#    #+#             */
/*   Updated: 2018/06/13 10:20:30 by wgourley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void *ret;

	ret = malloc(size);
	if (ret == NULL)
		return (NULL);
	ft_bzero(ret, size);
	return (ret);
}
