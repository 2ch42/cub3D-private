/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhyl <changhyl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 22:05:55 by changhyl          #+#    #+#             */
/*   Updated: 2023/10/11 21:25:29 by changhyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include "get_next_line.h"
#include "parse.h"

static void	init_checker(t_checker *checker)
{
	checker->north = 0;
	checker->south = 0;
	checker->west = 0;
	checker->east = 0;
	checker->floor = 0;
	checker->ceiling = 0;
}

static int	check_checker(t_checker *checker)
{
	if (checker->north == 1 && checker->south == 1 && checker->west == 1
		&& checker->east == 1 && checker->ceiling == 1 && checker->floor == 1)
		return (1);
	return (0);
}

static void	get_s_config(t_data *data, char *line)
{
	int	idx;
	int	id;

	id = check_id(line, &idx);
	if (id == 1)
		data->checker->north += 1;
	if (id == 2)
		data->checker->south += 1;
	if (id == 3)
		data->checker->west += 1;
	if (id == 4)
		data->checker->east += 1;
	if (id == 5)
		data->checker->floor += 1;
	if (id == 6)
		data->checker->ceiling += 1;
	if (id >= 1 && id <= 4)
		get_text(data, line, &idx, id);
	if (id == 5 || id == 6)
		get_rgb(data, line, &idx, id);
}

static char	*get_config(t_data *data)
{
	char		*line;

	init_checker(data->checker);
	line = get_next_line(data->fd);
	while (line)
	{
		if (check_if_map(line))
			break;
		get_s_config(data, line);
		free_line(line);
		line = get_next_line(data->fd);
	}
	if (!line)
		config_err();
	if (!(check_checker(data->checker)))
	{
		free_line(line);
		config_err();
	}
}

t_data	*get_data(const char *path)
{
	t_data	*data;
	char	*line;

	data->fd = open(path);
	if (data->fd < 0)
	{
		print_error("File Open Error\n");
		exit(1);
	}
	line = get_config(data);
	get_map(data, line);
	return (data);
}
