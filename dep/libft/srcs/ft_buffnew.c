/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buffnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgourley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 13:08:17 by wgourley          #+#    #+#             */
/*   Updated: 2018/06/22 13:36:21 by wgourley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_buff	*ft_buffnew(size_t buffsize, int me)
{
	t_buff *ret;
	
	(ret) = (t_buff *)ft_memalloc(sizeof(t_buff));
	if(buffsize == 0)
		(ret)->data = NULL;
	else
		(ret)->data = ft_memalloc(buffsize);
	(ret)->buff_size = buffsize;
	(ret)->meta = me;
	(ret)->pointer = (ret)->data + buffsize;
	(ret)->available = 0;
	return (ret);
}
