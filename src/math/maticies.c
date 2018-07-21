/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maticies.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgourley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 18:15:44 by wgourley          #+#    #+#             */
/*   Updated: 2018/07/21 18:15:44 by wgourley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>
#include <math.h>

t_matrix *get_rot_matrix_x(float deg)
{
	static t_matrix *mat = NULL;

	if (mat == NULL)
		mat = new_matrix(3, 3);
	mat->cells[2][2] = 1;
	mat->cells[0][0] = cos((deg / 180) * M_PI);
	mat->cells[0][1] = -sin((deg / 180) * M_PI);

	mat->cells[1][1] = cos((deg / 180) * M_PI);
	mat->cells[1][0] = sin((deg / 180) * M_PI);
	return (mat);
}

t_matrix *get_rot_matrix_y(float deg)
{
	static t_matrix *mat = NULL;

	if (mat == NULL)
		mat = new_matrix(3, 3);
	mat->cells[1][1] = 1;
	mat->cells[0][0] = cos((deg / 180) * M_PI);
	mat->cells[0][2] = sin((deg / 180) * M_PI);

	mat->cells[2][2] = cos((deg / 180) * M_PI);
	mat->cells[2][0] = -sin((deg / 180) * M_PI);
	return (mat);
}

t_matrix *get_rot_matrix_z(float deg)
{
	static t_matrix *mat = NULL;

	if (mat == NULL)
		mat = new_matrix(3, 3);
	mat->cells[0][0] = 1;
	mat->cells[1][1] = cos((deg / 180) * M_PI);
	mat->cells[1][2] = -sin((deg / 180) * M_PI);

	mat->cells[2][2] = cos((deg / 180) * M_PI);
	mat->cells[2][1] = sin((deg / 180) * M_PI);
	return (mat);
}

void rotate_surf(t_w3surface *s, float deg, t_matrix *(*f)(float))
{
	int x;
	t_point3 **points;
	t_point3 *hold;
	float r1;
	float r2;

	points = surf_to_point_list(s);
	
	x = 0;
	s->closest = NULL;
	r2 = 0;
	while (x < s->count)
	{
		hold = matrix_prod(points[x], f(deg));
		free(points[x]);
		points[x] = hold;
		if (s->closest == NULL)
			s->closest = hold;
		if (Z(hold) < Z(s->closest))
			s->closest = hold;
		x++;
	}
}