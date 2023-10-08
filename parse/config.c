/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhyl <changhyl@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 22:05:55 by changhyl          #+#    #+#             */
/*   Updated: 2023/10/08 22:28:00 by changhyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	init_checker(t_checker *checker)
{
	checker->north = 0;
	checker->south = 0;
	checker->west = 0;
	checker->east = 0;
	checker->ceiling = 0;
	checker->floor = 0;
}

int	check_checker(t_checker *checker)
{
	if (checker->north && checker->south && checker->west && checker->east && checker->ceiling && checker->floor)
		return (1);
	return (0);
}

int	check_config(const char *path)
{
	t_checker	*checker;

	init_checker(checker);
}

t_data	*get_data(const char *path)
{
		
}
