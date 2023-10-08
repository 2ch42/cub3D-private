/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhyl <changhyl@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 22:04:22 by changhyl          #+#    #+#             */
/*   Updated: 2023/10/08 22:26:57 by changhyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "parse.h"

static int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (*(str + i))
		i++;
	return (i);
}

static int	check_ext(const char *path)
{
	int	str_len;

	str_len = ft_strlen(path);
	if (path[str_len - 4] == '.' && path[str_len - 3] == 'c' && path[str_len - 2] == 'u' && path[str_len - 1] == 'b')
		return (1);
	return (0);
}

static int	check_path(const char *path)
{
	int	fd;

	fd = open(path);
	if (fd < 0)
	{
		print_error("File Open Error\n");
		return (0);
	}
	if (!(check_ext(path)))
	{
		print_error("File Extension Error\n");
		return (0);
	}
	return (1);
}

int	check_arg(int argc, char *argv[])
{
	if (argc != 2)
	{
		print_error("Argc Error\n");
		return (0);
	}
	if (!(check_path(argv[1])))
		return (0);
	return (1);
}
