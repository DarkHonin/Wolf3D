/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgourley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 23:55:37 by wgourley          #+#    #+#             */
/*   Updated: 2018/07/13 11:30:14 by wgourley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix_ft.h"

t_matrix	*new_matrix(t_coor rows, t_coor cols)
{
	t_matrix *ret;
	int	ind;

	ind = 0;
	ret = (t_matrix *)ft_memalloc(sizeof(t_matrix));
	ret->rows = rows;
	ret->cols = cols;
	ret->cells = (float **)ft_memalloc(rows * sizeof(float *));
	while(ind < rows)
		ret->cells[ind++] = (float *)ft_memalloc(sizeof(float) * cols);
	return (ret);
}

void		set_cell(t_matrix *mtr, t_coor r, t_coor c, float p)
{
	mtr->cells[r][c] = p;
}

float		*get_row(t_matrix *mtr, t_coor r)
{
	return (mtr->cells[r]);
}

float		**get_col(t_matrix *mtr, t_coor c)
{
	float **ret;
	t_coor in;

	in = 0;
	ret = ft_memalloc(sizeof(float) * mtr->cols);
	while (in < mtr->cols)
	{
		ret[in] = &(mtr->cells[in][c]);
		in++;
	}
	return (ret);
}

void		print_matrix(t_matrix *mtr)
{
	int r;
	int c;

	ft_putstr("Matrix dimention: [");
	ft_putnbr(mtr->rows);
	ft_putstr(", ");
	ft_putnbr(mtr->cols);
	ft_putendl("]");
	r = 0;
	c = 0;
	while (r < mtr->rows)
	{
		c = 0;
		ft_putchar('[');
		while (c < mtr->cols)
		{
			ft_putnbr(mtr->cells[r][c++]);
			if (c != mtr->cols)
				ft_putstr(", ");
		}
		ft_putendl("]");
		r++;
	}
}