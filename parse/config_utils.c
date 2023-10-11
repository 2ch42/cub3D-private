/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhyl <changhyl@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 16:24:15 by changhyl          #+#    #+#             */
/*   Updated: 2023/10/11 18:57:38 by changhyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "parse.h"

void	config_err(void)
{
	print_error("Config Error\n");
	exit(1);
}

int	check_whitespace(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	else if (c == '\v' || c == '\f' || c == '\r')
		return (1);
	return (0);
}

int	check_if_map(const char *s)
{
	int	i;

	i = 0;
	while (*(s + i))
	{
		if (*(s + i) == '0' || *(s + i) == '1')
			return (1);
		if (*(s + i) == 'N' && *(s + i + 1) != 'O')
			return (1);
		if (*(s + i) == 'S' && *(s + i + 1) != 'O')
			return (1);
		if (*(s + i) == 'W' && *(s + i + 1) != 'W')
			return (1);
		if (*(s + i) == 'E' && *(s + i + 1) != 'A')
			return (1);
		i++;
	}
	return (0);
}

int	check_id(const char *s, int *idx)
{
	*idx = 0;
	while (*(s + *idx) && check_whitespace(*(s + *idx)))
		*idx += 1;
	if (!(*(s + *idx)))
		return (0);
	if (*(s + *idx) == 'N' && (*(s + *idx + 1) == 'O'))
		return (1);
	if (*(s + *idx) == 'S' && (*(s + *idx + 1) == 'O'))
		return (2);
	if (*(s + *idx) == 'W' && (*(s + *idx + 1) == 'E'))
		return (3);
	if (*(s + *idx) == 'E' && (*(s + *idx + 1) == 'A'))
		return (4);
	if (*(s + *idx) == 'F')
		return (5);
	if (*(s + *idx) == 'C')
		return (6);
	return (0);
}
