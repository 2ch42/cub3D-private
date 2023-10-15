/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhyl <changhyl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 18:48:10 by changhyl          #+#    #+#             */
/*   Updated: 2023/10/15 21:04:57 by changhyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "parse.h"

void	map_err_exit(int errnum)
{
	if (errnum == 1)
		print_err_exit("No Map Found\n");
	if (errnum == 2)
		print_err_exit("Map Doesn't Fit\n");
	if (errnum == 3)
		print_err_exit("Map Is Invalid\n");
}

int	check_if_map(const char *s)
{
	int	i;
	int	count;
	int	space;

	if (!s)
		return (0);
	i = 0;
	count = 0;
	space = 0;
	while (*(s + i))
	{
		if (*(s + i) == '1')
			count++;
		else if (*(s + i) == '0')
			count++;
		else if (*(s + i) == 'N' || *(s + i) == 'S'
			|| *(s + i) == 'W' || *(s + i) == 'E')
			count++;
		else if (check_whitespace(*(s + i)))
			space++;
		else
			return (0);
		i++;
	}
	if (count > 0)
		return (1);
	return (0);
}

void	free_mapline(t_mapline **mapline)
{
	t_mapline	*p;
	t_mapline	*q;

	if (!mapline)
		return ;
	p = *mapline;
	if (!p)
		return ;
	while (p != NULL)
	{
		q = p->next;
		free(p);
		p = q;
	}
	free(mapline);
	mapline = NULL;
}
