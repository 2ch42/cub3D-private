/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhyl <changhyl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 22:48:05 by changhyl          #+#    #+#             */
/*   Updated: 2023/10/14 20:40:35 by changhyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "parse.h"
/*
static void	check_map_err(t_data *data)
{
	if (!(check_surr_char(data)))
		map_err_exit(3);
	if (!(check_col(data)))
		map_err_exit(3);
}

void	fill_arr(char *s1, char *s2, int width)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(s1);
	while (i < len)
	{
		s2[i] = s1[i];
		i++;
	}
	while (i < width)
	{
		s2[i] = '0';
		i++;
	}
}

void	make_arr(t_data *data, t_mapline **mapline)
{
	t_mapline	*p;
	int			len;
	int			i;

	p = *mapline;
	i = 0;
	while (i < data->map_h)
	{
		if (!p)
			print_err_exit("Map Error\n");
		fill_arr(p->line, data->map[i], data->map_w);
		p = p->next;
		i++;
	}
	free_mapline(mapline);
	check_map_err(data);
}
*/
