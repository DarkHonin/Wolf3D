/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bufffill.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgourley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 17:40:19 by wgourley          #+#    #+#             */
/*   Updated: 2018/06/18 17:40:19 by wgourley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**  ft_bufffill handles the procedure for filling up a buffer
**  it takes a function responsible for reading from a stream
**  and putting it in the buffer, returning the amount of bytes
**  actually handled.
**  
**  The function itself returns 0 if nothing has been read and 
**  the second paramater didnt fail.
**
**  Returns -1 if the reading function failed
**
**  Returns > 0 if everything went well
*/

int ft_bufffill(t_buff *buff, int (*reader)(int, void *, size_t))
{
    if (buff->data == NULL)
        buff->data = ft_memalloc(buff->buff_size);
    buff->available = reader(buff->meta, buff->data, buff->buff_size);
    ft_buffreset(buff);
    return (buff->available);
}