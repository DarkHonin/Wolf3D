/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgourley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 08:35:59 by wgourley          #+#    #+#             */
/*   Updated: 2018/05/26 13:01:38 by wgourley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_striteri(char *str, void (*f)(unsigned int, char *))
{
	unsigned int index;

	if (!str || !f)
		return ;
	index = 0;
	while (str[index] != '\0')
	{
		f(index, str + index);
		index++;
	}
}
