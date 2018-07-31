/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgourley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/30 17:33:59 by wgourley          #+#    #+#             */
/*   Updated: 2018/07/31 12:36:24 by wgourley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>
#include <stdio.h>
static void draw_point(t_point3 a)
{
	t_projected_point *q = standard_projection(&a);

	put_pixel(X(q) + WINDOW_C_W, Y(q) + WINDOW_C_H, 255, ((10 - Z((&a))) / 10) * 255, 0);
}

static void draw_line(t_line a)
{
	plot_line(a, 0.001, &draw_point);
}

int loop(void *e)
{
	line_itter(e, 4, &draw_line);
	flip();
	return (1);
}

int main(void)
{
	get_window();

	t_point3_list lst = MAKE_EMPTY_LIST(5);
	t_line	*lines;
	*lst = *MAKE_POINT(-WINDOW_C_W, 0, 0);
	*(lst + 1) = *MAKE_POINT(-WINDOW_C_W / 2, 0, 10);
	*(lst + 2) = *MAKE_POINT(0, 0, 10);
	*(lst + 3) = *MAKE_POINT(WINDOW_C_W / 2, 0, 10);
	*(lst + 4) = *MAKE_POINT(WINDOW_C_W, 0, 0);
	lines = list_to_lines(lst, 5, MAKE_POINT(0, 0, 1));
	start_loop(&loop, lines);
}