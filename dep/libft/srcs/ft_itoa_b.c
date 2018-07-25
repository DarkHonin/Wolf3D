/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgourley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 21:16:44 by wgourley          #+#    #+#             */
/*   Updated: 2018/07/04 21:16:44 by wgourley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_numlen(int num, int base)
{
	int remainder;
	int index;

	if (num == 0)
		return (1);
	remainder = num;
	index = 0;
	while (remainder != 0)
	{
		remainder = remainder / base;
		index++;
	}
	return (index);
}

static void	set_sign(char *bbuffer, int base, int *cchar)
{
	if (*cchar < 0 && base == 10)
	{
		bbuffer[0] = '-';
		*cchar *= -1;
	}
}


char	*ft_itoa_b(int num, int base)
{
	int		str_len;
	int		index;
	int		cchar;
	char	*bbuffer;

	str_len = ft_numlen(num, base);
	if (num < 0 && base == 10)
		str_len += 1;
	bbuffer = ft_strnew(str_len);
	if (!bbuffer)
		return ((char *)NULL);
	index = str_len - 1;
	while (index >= 0)
	{
		if (bbuffer[index] == '-')
			break ;
		cchar = num % base;
		set_sign(bbuffer, base, &cchar);
		bbuffer[index] = ITOA_CHARS[cchar];
		num /= base;
		index--;
	}
	bbuffer[str_len] = '\0';
	return (bbuffer);
}