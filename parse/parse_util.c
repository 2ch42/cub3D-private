/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhyl <changhyl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 21:10:56 by changhyl          #+#    #+#             */
/*   Updated: 2023/10/14 21:21:12 by changhyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	check_whitespace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n')
		return (1);
	else if (c == '\v' || c == '\f' || c == '\r')
		return (1);
	return (0);
}

int	check_if_map(const char *s)
{
	int	i;
	int	one_count;
	int	zero_count;
	int	char_count;

	if (!s)
		return (0);
	i = 0;
	while (*(s + i))
	{
		if (*(s + i) == '1')
			one_count++;
		else if (*(s + i) == '0')
			zero_count++;
		else if (*(s + i) == 'N' || *(s + i) == 'S'
			|| *(s + i) == 'W' || *(s + i) == 'E')
			char_count++;
		else if (!(check_whitespace(*(s + i))))
			return (0);
		i++;
	}
	if (one_count + zero_count + char_count > 0)
		return (1);
	return (0);
}

void	print_err_exit(const char *s)
{
	perror(s);
	write(2, "Error\n", 7);
	exit(1);
}
