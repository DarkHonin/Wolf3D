/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgourley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 10:33:48 by wgourley          #+#    #+#             */
/*   Updated: 2018/08/17 13:10:10 by wgourley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

void	draw_map(void)
{
	t_map		*m;
	t_size		i;
	t_value_v	a;
	t_value_v	b;

	a = create_value_v(2);
	b = create_value_v(2);
	m = get_map(NULL);
	i[1] = 0;
	while ((i[1]++) <= m->size[1])
	{
		i[0] = 0;
		while (i[0] < m->size[0])
		{
			a[0] = i[0] * MINI_SIZE;
			a[1] = (i[1] - 1) * MINI_SIZE;
			b[0] = (i[0] + 1) * MINI_SIZE;
			b[1] = (i[1]) * MINI_SIZE;
			draw_rect(a, b, 2, (t_color){(m->points[(m->size[1] *
							(i[1] - 1)) + i[0]] / 4) * 255, 100, 100});
			i[0]++;
		}
	}
	free(a);
	free(b);
}
