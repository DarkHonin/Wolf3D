/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgourley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 13:51:41 by wgourley          #+#    #+#             */
/*   Updated: 2018/05/26 12:49:19 by wgourley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(void const *content, size_t content_s)
{
	t_list	*ret;
	void	*hold;

	ret = (t_list *)ft_memalloc(sizeof(t_list));
	if (!ret)
		return ((t_list *)NULL);
	if (content_s && content)
	{
		hold = ft_memalloc(content_s);
		ft_memcpy(hold, content, content_s);
	}
	else
	{
		hold = NULL;
		ret->content_size = 0;
		return (ret);
	}
	ret->content_size = content_s;
	ret->content = hold;
	ret->next = NULL;
	return (ret);
}
