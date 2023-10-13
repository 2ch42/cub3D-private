/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhyl <changhyl@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 18:19:54 by changhyl          #+#    #+#             */
/*   Updated: 2023/10/13 16:35:46 by changhyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "parse.h"

static char	*cub_substr(char const *s, unsigned int start, size_t len)
{
	char		*ret_str;
	size_t		i;
	size_t		real_len;

	i = 0;
	real_len = 0;
	while (real_len + start < ch_strlen(s) && real_len < len)
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
	free(s);
	s = NULL;
	return (ret_str);
}

void	get_f_rgb(t_data *data, char *line, int *idx)
{
	if (!data || !line)
		return ;
	data->floor->red = ft_atoi(line);
	while (*(line + *idx) != ',')
		*idx += 1;
	*idx += 1;
	line = cub_substr(line, *idx, ch_strlen(line) - *idx - 1);
	data->floor->green = ft_atoi(line);
	while (*(line + *idx) != ',')
		*idx += 1;
	*idx += 1;
	line = cub_substr(line, *idx, ch_strlen(line) - *idx - 1);
	data->floor->blue = ft_atoi(line);
}

void	get_c_rgb(t_data *data, char *line, int *idx)
{
	if (!data || !line)
		return ;
	data->ceiling->red = ft_atoi(line);
	while (*(line + *idx) != ',')
		*idx += 1;
	*idx += 1;
	line = cub_substr(line, *idx, ch_strlen(line) - *idx - 1);
	data->ceiling->green = ft_atoi(line);
	while (*(line + *idx) != ',')
		*idx += 1;
	*idx += 1;
	line = cub_substr(line, *idx, ch_strlen(line) - *idx - 1);
	data->ceiling->blue = ft_atoi(line);
}
