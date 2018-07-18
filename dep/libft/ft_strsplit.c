/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgourley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 16:33:16 by wgourley          #+#    #+#             */
/*   Updated: 2018/05/26 12:07:07 by wgourley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static char		*get_slice(const char *str, size_t max, char delim, size_t *st)
{
	size_t end;
	size_t start;

	start = ft_strchr_n(str, delim) - str;
	end = ft_strchr(str + start, delim) - str;
	if (end > max)
		end = ft_strchr(str + start, '\0') - str;
	if (end > max || end - start == 0)
		return ((char *)NULL);
	*st += end;
	return (ft_strndup(str + start, end - start));
}

char			**ft_strsplit(const char *str, char delim)
{
	char	**ret;
	size_t	start;
	int		put;
	size_t	max;

	if (!str)
		return ((char **)NULL);
	ret = (char **)ft_memalloc(sizeof(char *) * (ft_count_w(str, delim) + 1));
	if (!ret)
		return ((char **)NULL);
	start = 0;
	put = 0;
	while (1)
	{
		max = ft_strlen(str + start);
		ret[put] = get_slice(str + start, max, delim, &start);
		if (!ret[put])
			break ;
		put++;
	}
	return (ret);
}
