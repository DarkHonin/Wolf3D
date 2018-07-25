/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_w.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgourley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 08:27:08 by wgourley          #+#    #+#             */
/*   Updated: 2018/05/26 13:03:48 by wgourley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_count_w(const char *str, char delim)
{
	int				a;
	unsigned int	count;

	a = 0;
	count = 0;
	while (str[a])
	{
		if ((str[a] != delim) && (str[a + 1] == delim || str[a + 1] == '\0'))
			count++;
		a++;
	}
	return (count);
}
