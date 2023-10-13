/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhyl <changhyl@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 22:48:05 by changhyl          #+#    #+#             */
/*   Updated: 2023/10/13 22:59:00 by changhyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

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
		fill_arr(mapline->line, data->map[i], data->map_w);
		p = p->next;
		i++;
	}
	free_mapline(mapline);
	check_map_err(t_data *data);
}
