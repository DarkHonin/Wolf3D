/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgourley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/30 17:33:59 by wgourley          #+#    #+#             */
/*   Updated: 2018/08/07 14:36:58 by wgourley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>
#include <stdio.h>
#include <math.h>
#include <3dft.h>



void	draw_player()
{
	t_player			*player;
	t_map				*map;
	t_projected_point	*pc;
	t_projected_point	*pp;
	float				rad;

	map = get_map();
	player = get_player();
	
	rad = (Z(player) / 180) * M_PI;
	pc = clone_matrix(player);
	X(pc) *= (map->w * 12) + 2;
	Y(pc) *= (map->h * 12) + 2;
	pp = MAKE_EMPTY_POINT;
	X(pp) = (cos(rad) * 10) + X(pc);
	Y(pp) = (sin(rad) * 10) + Y(pc);
	draw_line(pc, pp, (t_color){255, 0, 0});
	put_pixel(X(pc), Y(pc), 255, 255, 255);
	put_pixel(X(pp), Y(pp), 0, 0, 255);
	
}

void	minmap(t_map *map)
{
	t_len	x;
	t_len	y;
	t_projected_point	*a;
	t_projected_point	*b;
	int 	color;

	y = 0;
	a = new_matrix(1, 2);
	b = new_matrix(1, 2);
	X(a) = 0;
	Y(a) = 0;
	X(b) = (map->w * 12) + 2;
	Y(b) = (map->h * 12) + 2;
	draw_rect(a, b, (t_color){125,125,125});
	while (y < map->h)
	{
		x = 0;
		while (x < map->w)
		{
			X((a)) = (x * 12) + 2;
			Y((a)) = (y * 12) + 2;
			X((b)) = (x * 12) + 2 + 10;
			Y((b)) = (y * 10) + ((y + 1) * 2) + 10;
			color = map->tiles[y][x];
			draw_rect(a, b, (t_color){color * 25,
										(color % 4) * 25,
										(color % 8) * 25});
			x++;
		}
		y++;
	}
	del_matrix(a);
	del_matrix(b);
	draw_player();
}

int		loop(t_map	*map)
{
	minmap(map);
	flip();
	return (1);
}

int	key(int keycode)
{
	float		rad;
	t_player	*p;

	if (keycode == KEY_ESC)
		close_window();
	p = get_player();
	Z(p) += 10 * (keycode == KEY_RIGHT);
	Z(p) -= 10 * (keycode == KEY_LEFT);

	rad = (Z(p) / 180) * M_PI;
	Y(p) += sin(rad) * (keycode == KEY_UP) * 0.01;
	Y(p) -= sin(rad )* (keycode == KEY_DOWN) * 0.1;
	X(p) += cos(rad) * (keycode == KEY_UP) * 0.01;
	X(p) -= cos(rad) * (keycode == KEY_DOWN) * 0.1;
	clean();
	ft_putnbr(keycode);
	ft_putendl("");
	return (1);
}



int main(void)
{
	t_map *e;

	get_window();
	e = get_map();
	ft_putstr("Map size: [");
	ft_putnbr(e->w);
	ft_putstr(" : ");
	ft_putnbr(e->h);
	ft_putendl(" ]");
	mlx_key_hook(get_window()->window_pointer, &key, NULL);
	start_loop(&loop, e);
}