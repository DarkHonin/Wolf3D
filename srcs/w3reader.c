/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w3reader.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgourley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 11:35:03 by wgourley          #+#    #+#             */
/*   Updated: 2018/08/17 14:49:58 by wgourley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>
#include <fcntl.h>
#include <get_next_line.h>
#include <unistd.h>

static	void	add_values(char *str, t_value_v *p, t_len *count)
{
	char		**parts;
	t_len		i;

	parts = ft_strsplit(str, ' ');
	i = 0;
	while (parts[i])
	{
		append_to_value_v(p, *count, ft_atoi(parts[i]));
		free(parts[i++]);
		(*count)++;
	}
	free(str);
	free(parts);
}

t_map			*read_map(char *file)
{
	int			fd;
	t_map		*m;
	char		*line;
	t_value_v	values;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		file_error(file);
	m = (t_map *)ft_memalloc(sizeof(t_map));
	m->size[1] = 0;
	m->size[0] = 0;
	values = create_value_v(0);
	while (get_next_line(fd, &line))
	{
		ft_putstr("Line: ");
		ft_putendl(line);
		add_values(line, &values, &(m->size[0]));
		m->size[1]++;
	}
	free(line);
	m->points = values;
	m->size[0] = m->size[0] / m->size[1];
	m->redraw = 1;
	return (m);
}

t_map			*get_map(char *str)
{
	static t_map *ret = NULL;

	if (ret)
		return (ret);
	ret = read_map(str);
	return (ret);
}
