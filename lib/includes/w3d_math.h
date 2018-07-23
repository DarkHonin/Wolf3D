/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w3d_math.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgourley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 10:54:22 by wgourley          #+#    #+#             */
/*   Updated: 2018/07/22 10:54:22 by wgourley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef W3D_MATH_H
# define W3D_MATH_H

#include <wolf3d.h>
#include <math.h>


void 		rotate_surf(t_w3surface *s, float deg, t_matrix *(*f)(float));
t_matrix 	*get_rot_matrix_x(float deg);
t_matrix 	*get_rot_matrix_y(float deg);
t_matrix 	*get_rot_matrix_z(float deg);
float		dst_from_center(t_point3 *e);
t_line		*pnts_to_line(t_point3 *a, t_point3 *b);
float		point3_dot(t_point3 *a, t_point3 *b);
t_point3	*point3_dif(t_point3 *a, t_point3 *b);
t_point3	*point3_sum(t_point3 *a, t_point3 *b);
t_point3	*cross(t_point3 *a, t_point3 *b);

#endif