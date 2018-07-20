/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w3d_generation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgourley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 22:56:18 by wgourley          #+#    #+#             */
/*   Updated: 2018/07/20 22:56:18 by wgourley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef W3D_GENERATION_H
# define W3D_GENERATION_H

#include <wolf3d.h>

t_space		*make_t_space();
t_w3surface	*make_t_w3surface();
t_point3	*make_t_point3(float x, float y, float z);
void		free_t_space(t_space **e);
void		free_t_w3surface(t_w3surface **surf);


#endif