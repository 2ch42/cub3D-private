/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhyl <changhyl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 22:04:22 by changhyl          #+#    #+#             */
/*   Updated: 2023/10/11 17:21:24 by changhyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "get_next_line.h"
#include "parse.h"

static int	check_ext(const char *path)
{
	int	str_len;

	str_len = ch_strlen(path);
	if (path[str_len - 4] == '.' && path[str_len - 3] == 'c'
		&& path[str_len - 2] == 'u' && path[str_len - 1] == 'b')
		return (1);
	return (0);
}

int	check_arg(int argc, char *argv[])
{
	if (argc != 2)
	{
		print_error("Argc Error\n");
		return (0);
	}
	if (!(check_ext(argv[1])))
		print_error("File Extension Error\n");
	return (1);
}
