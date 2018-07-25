/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buffstat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgourley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 13:35:10 by wgourley          #+#    #+#             */
/*   Updated: 2018/06/19 14:37:06 by wgourley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**  ft_buffstat returns the amount of bytes available
**  in the buffer
*/

int	ft_buffstat(t_buff *e)
{
	return ((e->data - e->pointer) + e->available);
}
