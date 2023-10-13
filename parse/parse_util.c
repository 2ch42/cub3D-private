/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhyl <changhyl@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 21:10:56 by changhyl          #+#    #+#             */
/*   Updated: 2023/10/13 18:01:57 by changhyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void	print_error(const char *s)
{
	perror(s);
	write(2, "Error\n", 7);
	return ;
}

void	print_err_exit(const char *s)
{
	print_error(s);
	exit(1);
}

void	free_line(char *line)
{
	free(line);
	line = NULL;
	return ;
}

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

	if (!s)
		return (0);
	i = 0;
	while (*(s + i))
	{
		if (!(*(s + i + 1)))
			return (0);
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
