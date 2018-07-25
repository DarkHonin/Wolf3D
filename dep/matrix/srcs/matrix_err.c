/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_err.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgourley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 11:35:01 by wgourley          #+#    #+#             */
/*   Updated: 2018/07/13 11:37:30 by wgourley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix_ft.h"

void	matrix_valid_multiple(t_matrix *m1, t_matrix *m2)
{
	if (m1->cols != m2->rows)
	{
		ft_putendl("Matrix multiple not valid:");
		print_matrix(m1);
		print_matrix(m2);
		exit(2);
	}
}