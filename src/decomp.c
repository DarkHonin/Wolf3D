/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decomp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgourley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 22:41:26 by wgourley          #+#    #+#             */
/*   Updated: 2018/07/20 22:41:26 by wgourley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <w3d_generation.h>

void	free_t_space(t_space **e)
{
	t_w3surface **kids;

	kids = (*e)->entities->data;

}

void	free_t_w3surface(t_w3surface **surf)
{
	t_point3	**pnts;
	size_t		max;
	size_t		index;

	ft_putendl("Freeing surface");
	index = 0;
	pnts = (*surf)->points->data;
	max = vect_len((*surf)->points);
	ft_putstr("Point count: ");
	ft_putnbr(max);
	ft_putendl("");
	while (index < max)
	{
		free(pnts[index]);
		index++;
	}
	free((*surf)->points);
	free(*surf);
}