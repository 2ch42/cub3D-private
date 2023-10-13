/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhyl <changhyl@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 18:48:10 by changhyl          #+#    #+#             */
/*   Updated: 2023/10/13 20:42:08 by changhyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	map_err_exit(int errnum)
{
	if (errnum == 1)
		print_err_exit("No Map Found\n");
	if (errnum == 2)
		print_err_exit("Map Doesn't Fit\n");
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
