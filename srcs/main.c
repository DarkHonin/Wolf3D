/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgourley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/30 17:33:59 by wgourley          #+#    #+#             */
/*   Updated: 2018/08/06 13:16:55 by wgourley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>
#include <stdio.h>

void	minmap(t_map *map)
{
	t_len	x;
	t_len	y;
	int		posx;
	int		posy;
	int 	color;

	y = 0;
	draw_rect(0, 0, 
		MAKE_SIZE((map->w * 10) + ((map->w + 1) * 2), (map->h * 10) + ((map->h + 1) * 2)),
		(t_color){100, 100, 100});
	while (y < map->h)
	{
		x = 0;
		while (x < map->w)
		{
			posx = (x * 10) + ((x + 1) * 2);
			posy = (y * 10) + ((y + 1) * 2);
			color = map->tiles[y][x];
			draw_rect(posx, posy, MAKE_SIZE(10, 10), (t_color){
																color * 25,
																(color % 2) * 25,
																(color % 4) * 25});
			x++;
		}
		y++;
	}
}

int		loop(t_map	*map)
{
	//clean();
	minmap(map);
	flip();
	return (1);
}

int main(void)
{
	t_map *e;


	get_window();
	e = read_map("map.w3");

	start_loop(&loop, e);
}