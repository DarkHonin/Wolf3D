/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w3d_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgourley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 10:23:26 by wgourley          #+#    #+#             */
/*   Updated: 2018/07/17 10:28:38 by wgourley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>
#include <stdlib.h>

void	w3_std_error(char *msg)
{
	ft_putstr("STD_ERROR: ");
	ft_putstr(SDL_GetError());
	ft_putstr(" : ");
	ft_putendl(msg);
	exit(-1);
}