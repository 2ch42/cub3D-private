/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhyl <changhyl@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 21:10:56 by changhyl          #+#    #+#             */
/*   Updated: 2023/10/11 21:11:06 by changhyl         ###   ########.fr       */
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

void	print_err_exit(const char *s) // may add free_data later.
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
