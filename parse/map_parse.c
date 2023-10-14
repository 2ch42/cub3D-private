/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhyl <changhyl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 16:21:28 by changhyl          #+#    #+#             */
/*   Updated: 2023/10/14 22:28:33 by changhyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> //
#include <stdlib.h>
#include "get_next_line.h"
#include "parse.h"

static t_mapline	*new_mapline(char *line)
{
	t_mapline	*p;

	p = (t_mapline *)malloc(sizeof(t_mapline));
	if (!p)
		return (NULL);
	p->next = NULL;
	p->line = line;
	return (p);
}

static t_mapline	**link_map(t_data *data, char *line)
{
	t_mapline	*p;
	t_mapline	*q;
	t_mapline	**mapline;

	p = new_mapline(line);
	mapline = &p;
	while (line && check_if_map(line))
	{
		q = new_mapline(line);
		q = p->next;
		p = p->next;
		line = get_next_line(data->fd);
	}
	return (mapline);
}

void	mov_to_arr(t_data *data, t_mapline **mapline)
{
	t_mapline	*p;

	p = *mapline;
	data->map_w = 0;
	data->map_h = 0;
	if (!p)
		return ;
	while (p)
	{
		if (!(p->line))
			print_err_exit("Unknown Error\n");
		if (ch_strlen(p->line) > data->map_w)
			data->map_w = ch_strlen(p->line);
		data->map_h++;
		p = p->next;
	}
	if (!data->map_w || !data->map_h)
		map_err_exit(2);
	data->map = (char **)malloc(sizeof(char *) * (data->map_h + 1));
	if (!(data->map))
		return ;
	*(data->map + data->map_h) = 0;
	make_arr(data, mapline);
}

void	get_map(t_data *data, char *line)
{
	t_mapline	**mapline;

	if (!data || !line)
		print_err_exit("Unknown Error\n");
	while (!(check_if_map(line)) && line)
	{
		free(line);
		line = get_next_line(data->fd);
	}
	if (!line)
		map_err_exit(1);
	mapline = link_map(data, line); //Problem start from Here.
	if (!mapline)
		map_err_exit(1);
	while (line)
	{
		if (check_if_map(line))
			map_err_exit(2);
		free(line);
		line = get_next_line(data->fd);
	}
	if (line)
		free(line);
	mov_to_arr(data, mapline);
}
