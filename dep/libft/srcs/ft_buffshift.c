/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buffshift.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgourley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 13:50:48 by wgourley          #+#    #+#             */
/*   Updated: 2018/06/12 10:14:32 by wgourley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**  ft_buffshift moves all the remaining data in it
**  to the start of the buffer and resets the pointer
**  returning a pointer to where the data ends.
**
**  the amount of bytes empty should then be caluculated
**  via pointer arithmatic
*/

void	*ft_buffshift(t_buff *buff)
{
	size_t	move_s;
	void	*ret;

	move_s = ft_buffstat(buff);
	ft_memmove(buff->data, buff->pointer, move_s);
	ret = buff->data + move_s;
	ft_bzero(ret, buff->buff_size - move_s);
	ft_buffreset(buff);
	return (ret);
}
