/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w3reader.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgourley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 11:35:03 by wgourley          #+#    #+#             */
/*   Updated: 2018/08/07 12:44:44 by wgourley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>
#include <fcntl.h>
#include <vect_ft.h>
#include <get_next_line.h>
#include <unistd.h>
#include <stdio.h>

static t_vector	parse_line(char *line)
{
	t_vector	ret;
	char		**subs;
	int			value;
	int			index;

	ft_putstr("Splitting: ");
	ft_putendl(line);
	ret = MAKE_VECT(sizeof(int));
	subs = ft_strsplit(line, ' ');
	index = 0;
	while (subs[index])
	{
		value = ft_atoi(subs[index]);
		vect_push(ret, &value);
		free(subs[index]);
		index++;
	}
	return (ret);
}

static void	to_int_map(t_vector e, t_map *a)
{
	t_vector	*lines;
	t_len		line_c;

	ft_putendl("Parsing data");
	a->tiles = (int	**)ft_memalloc(sizeof(int*) * a->h);
	lines	= e->data;
	line_c = 0;
	while (line_c < a->h)
	{
		a->tiles[line_c] = lines[line_c]->data;
		line_c++;
	}

}

t_map	*read_map(char *file)
{
	int			fd;
	char		*line;
	t_map		*ret;
	t_vector	lines;
	t_vector	hold;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (NULL);
	ft_putendl("Starting file read");
	ret = NULL;
	lines = MAKE_VECT(sizeof(t_vector));
	ret = (t_map *)ft_memalloc(sizeof(t_map));
	ret->w = 0;
	ret->h = 0;
	while(get_next_line(fd, &line) > 0)
	{
		hold = parse_line(line);
		ret->w = vect_len(hold);
		vect_push(lines, &hold);
		ret->h++;
		free(line);
	}
	to_int_map(lines, ret);
	free(line);
	close(fd);
	return (ret);
}

t_map	*get_map()
{
	static t_map *ret = NULL;

	if (ret)
		return (ret);
	ret = read_map("map.w3");
	return (ret);
}