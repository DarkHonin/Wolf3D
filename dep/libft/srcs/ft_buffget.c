/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buffget.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgourley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 13:16:02 by wgourley          #+#    #+#             */
/*   Updated: 2018/06/26 11:08:26 by wgourley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**  ft_buffget reads the spesified amount of bytes from the data
**  moving the pointer up the required amount of bytes.
**
**  If there are not enugh bytes for the read but there are left
**  then it returns -1 and noting is done.
**
**  If the read was sucsessful then it returns 1.
**
**  If there are no bytes left it then returns 0;
*/

int	ft_buffget(size_t get_size, t_buff *buff, void *data)
{
	size_t remaining;

	remaining = ft_buffstat(buff);
	if (remaining == 0)
		return (0);
	if (remaining < get_size)
		return (-1);
	ft_memcpy(data, buff->pointer, get_size);
	buff->pointer += get_size;
	return (1);
}
