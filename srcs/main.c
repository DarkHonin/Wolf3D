/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgourley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/30 17:33:59 by wgourley          #+#    #+#             */
/*   Updated: 2018/08/14 14:40:50 by wgourley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>
#include <stdio.h>
#include <math.h>

int redraw = 1;

int		loop(t_map	*map)
{
	if (redraw)
	{
		trace();
		draw_map();
		draw_player();
		flip();
	}
	redraw = 0;
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
	p[1] += (sinf(rad) * (keycode == KEY_UP)) * 0.01;
	p[1] -= (sin(rad) * (keycode == KEY_DOWN)) * 0.1;
	p[0] += (cos(rad) * (keycode == KEY_UP)) * 0.01;
	p[0] -= (cos(rad) * (keycode == KEY_DOWN)) * 0.1;
	clean();
	ft_putnbr(keycode);
	ft_putendl("");
	redraw = 1;
	return (1);
}


int main(void)
{
	t_map *e;

	get_window();
	e = get_map();
	ft_putstr("Map size: [");
	ft_putnbr(e->size[0]);
	ft_putstr(" : ");
	ft_putnbr(e->size[1]);
	ft_putendl(" ]");
	mlx_key_hook(get_window()->window_pointer, &key, NULL);
	start_loop(&loop, e);
}