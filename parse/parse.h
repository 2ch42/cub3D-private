/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhyl <changhyl@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 19:23:25 by changhyl          #+#    #+#             */
/*   Updated: 2023/10/08 22:25:12 by changhyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

typedef struct	s_img
{
	void	*img;
	int		img_width;
	int		img_height;
}	t_img;

typedef struct	s_rgb
{
	int	red;
	int	green;
	int	blue;
}	t_rgb;

typedef struct	s_data
{
	char	**map;
	t_img	*north;
	t_img	*south;
	t_img	*west;
	t_img	*east;
	t_rgb	ceiling;
	t_rgb	floor;
}	t_data;

typedef struct	s_checker
{
	int	north;
	int south;
	int	west;
	int	east;
	int	ceiling;
	int	floor;
}	t_checker;

void	print_error(const char *s);
int		check_arg(int argc, char *argv[]);

#endif
