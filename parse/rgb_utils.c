/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhyl <changhyl@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 18:36:03 by changhyl          #+#    #+#             */
/*   Updated: 2023/10/11 19:20:36 by changhyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int	is_rgb_input(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	if (c == ',')
		return (1);
	if (check_whitespace(c))
		return (1);
	else
		return (0);
}

void	add_rgb_err(char *line, int *idx)
{
	int	i;
	int	count;

	i = *idx;
	count = 0;
	while (*(line + i))
	{
		if (ft_isdigit(*(line + i)))
		{
			count++;
			while (*(line + i) && check_whitespace(*(line + i)))
				i++;
			if (ft_isdigit(*(line + i)))
				break;
			i--;
		}
		i++;
	}
	if (count != 3)
		print_err_exit("Rgb Inptu Error\n");
}
