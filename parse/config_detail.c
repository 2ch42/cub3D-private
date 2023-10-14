/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_detail.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhyl <changhyl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 17:12:58 by changhyl          #+#    #+#             */
/*   Updated: 2023/10/14 21:47:09 by changhyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h> //
#include "parse.h"

char	*ch_substr(char const *s, int start, size_t len)
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
	return (ret_str);
}

void	get_text(t_data *data, char *line, int *idx, int id)
{
	char	*loc;
	int		start;

	if (!data || !line)
		print_err_exit("Unexpected Error\n");
	*idx += 2;
	while (*(line + *idx) && check_whitespace(*(line + *idx)))
		*idx += 1;
	if (!(*(line + *idx)))
	{
		free(line);
		print_err_exit("Config Error\n");
	}
	start = *idx;
	while (*(line + *idx) && !(check_whitespace(*(line + *idx))))
		*idx += 1;
	loc = ch_substr(line, start, *idx - start);
	if (id == 1)
		data->north = loc;
	if (id == 2)
		data->south = loc;
	if (id == 3)
		data->west = loc;
	if (id == 4)
		data->east = loc;
}

static void	check_rgb_err(char *line, int *idx)
{
	int	i;
	int	comma;

	if (!line)
		print_err_exit("Unexpected Error\n");
	i = *idx;
	while (*(line + i))
	{
		if (!(is_rgb_input(*(line + i))))
			print_err_exit("Rgb Input Error\n");
		i++;
	}
	i = *idx;
	comma = 0;
	while (*(line + i))
	{
		if (*(line + i) == ',')
			comma++;
		i++;
	}
	if (comma != 2)
		print_err_exit("Rgb Input Error\n");
	add_rgb_err(line, idx);
}

void	get_rgb(t_data *data, char *line, int *idx, int id)
{
	if (!data || !line)
		return ;
	*idx += 1;
	while (*(line + *idx) && check_whitespace(*(line + *idx)))
		*idx += 1;
	if (!(*(line + *idx)))
		print_err_exit("Rgb Error\n");
	check_rgb_err(line, idx);
	if (id == 5)
		get_f_rgb(data, line, idx);
	if (id == 6)
		get_c_rgb(data, line, idx);
}
