/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buffdel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgourley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 13:12:07 by wgourley          #+#    #+#             */
/*   Updated: 2018/06/22 15:51:16 by wgourley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_buffdel(t_buff *buff)
{
	if (!buff)
		return ;
	if (buff->data)
		free((buff)->data);
	(buff)->data = NULL;
	(buff)->pointer = NULL;
	free((buff));
}
