/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgourley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 10:41:26 by wgourley          #+#    #+#             */
/*   Updated: 2018/05/26 12:57:35 by wgourley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *in, t_list *(*f)(t_list *pa))
{
	t_list *ret;

	ret = (void *)0;
	if (!in)
		return (ret);
	if (in)
		ret = f(in);
	if (in->next)
		ret->next = ft_lstmap(in->next, f);
	return (ret);
}
