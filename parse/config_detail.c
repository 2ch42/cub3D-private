/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_detail.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhyl <changhyl@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 17:12:58 by changhyl          #+#    #+#             */
/*   Updated: 2023/10/10 21:57:29 by changhyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "parse.h"

static char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*ret_str;
	size_t		i;
	size_t		real_len;

	i = 0;
	real_len = 0;
	while (real_len + start < ft_strlen(s) && real_len < len)
		real_len++;
	ret_str = (char *)malloc(sizeof(char) * (real_len + 1));
	if (!ret_str)
		return (NULL);
	while (i < real_len)
	{
		*(ret_str + i) = *(s + start + i);
		i++;
	}
	*(ret_str + i) = '\0';
	return (ret_str);
}

void	get_text(t_data *data, char *line, int *idx, int id)
{
	char	*loc;
	int		start;

	*idx += 2;
	while (*(line + *idx) && check_whitspace(*(line + *idx)))
		*idx += 1;
	if (!(*(line + *idx)))
	{
		free(line);
		config_err();
	}
	start = *idx;
	while (*(line + *idx) && !(check_whitespace(*(line + *idx))))
		*idx += 1;
	loc = ft_substr(line, start, (unsigned int) start, *idx - start + 1);
	if (id == 1)
		data->north = loc;
	if (id == 2)
		data->south = loc;
	if (id == 3)
		data->west = loc;
	if (id == 4)
		data->west = loc;
}

void	init_rgb(t_data *data)
{
	data->ceiling->red = -1;
	data->ceiling->green = -1;
	data->ceiling->blue = -1;
	data->floor->red = -1;
	data->floor->green = -1;
	data->floor->blue = -1;
}

void	get_rgb(t_data *data, char *line, int *idx, int id)
{
		
}
