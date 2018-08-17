/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgourley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/30 17:33:59 by wgourley          #+#    #+#             */
/*   Updated: 2018/08/17 13:10:59 by wgourley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>
#include <stdio.h>
#include <math.h>

int	loop(t_map *map)
{
	if (map->redraw)
	{
		trace();
		draw_map();
		draw_player();
		flip();
	}
	map->redraw = 0;
	return (map != NULL);
}

int	key(int keycode)
{
	float		rad;
	t_player	p;

	if (keycode == KEY_ESC)
		close_window();
	p = get_player();
	p[2] += 10 * (keycode == KEY_RIGHT);
	p[2] -= 10 * (keycode == KEY_LEFT);
	rad = (p[2] / 180) * M_PI;
	p[1] += (sinf(rad) * (keycode == KEY_UP)) * 0.05;
	p[1] -= (sin(rad) * (keycode == KEY_DOWN)) * 0.1;
	p[0] += (cos(rad) * (keycode == KEY_UP)) * 0.05;
	p[0] -= (cos(rad) * (keycode == KEY_DOWN)) * 0.1;
	clean();
	ft_putnbr(keycode);
	ft_putendl("");
	get_map(NULL)->redraw = 1;
	return (1);
}

int	main(int ac, char **av)
{
	t_map *e;

	get_window();
	if (ac != 2)
		e = get_map("map.w3");
	else
		e = get_map(av[1]);
	ft_putstr("Map size: [");
	ft_putnbr(e->size[0]);
	ft_putstr(" : ");
	ft_putnbr(e->size[1]);
	ft_putendl(" ]");
	mlx_key_hook(get_window()->window_pointer, &key, NULL);
	start_loop(&loop, e);
}
