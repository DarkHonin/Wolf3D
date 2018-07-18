/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgourley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 11:45:32 by wgourley          #+#    #+#             */
/*   Updated: 2018/05/26 12:48:05 by wgourley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putchar_fd(char e, int fd)
{
	int	*unicode;

	if (ft_isascii(e))
		write(fd, &e, 1);
	else
	{
		unicode = (int *)ft_memalloc(sizeof(int) * 2);
		ft_memcpy(unicode, "\u00f8", 2);
		unicode[1] = e;
		write(fd, unicode, 2);
	}
}
