/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgourley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 11:50:27 by wgourley          #+#    #+#             */
/*   Updated: 2018/05/26 12:51:16 by wgourley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putnbr_fd(int a, int fd)
{
	if (a < 0)
	{
		ft_putchar_fd('-', fd);
		if (-(a / 10) != 0)
			ft_putnbr_fd(-(a / 10), fd);
		ft_putnbr_fd(-(a % 10), fd);
	}
	else if (a >= 10)
	{
		ft_putnbr_fd(ABS(a / 10), fd);
		ft_putnbr_fd(ABS(a % 10), fd);
	}
	else
		ft_putchar_fd(a + '0', fd);
}
