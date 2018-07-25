/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgourley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 00:47:15 by wgourley          #+#    #+#             */
/*   Updated: 2018/06/13 10:19:16 by wgourley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	resolve_sign(int total, int sign)
{
	total *= sign;
	if (sign == 1 && total < 0)
		return (total);
	if (sign == -1 && total > 0)
		return (0);
	return (total);
}

int			ft_atoi(char const *str)
{
	int		total;
	size_t	i;
	int		sign;

	i = -1;
	total = 0;
	sign = 1;
	while (str[++i] != '\0')
		if (!ft_isdigit(str[i]))
		{
			if (total != 0)
				break ;
			if (str[i] == '-' && ft_isdigit(str[i + 1]))
				sign = -1;
			else if (!ft_isspace(str[i]) &&
					!(str[i] == '+' && ft_isdigit(str[i + 1])))
				break ;
		}
		else
		{
			total *= 10;
			total += str[i] - '0';
		}
	return (resolve_sign(total, sign));
}
