/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhyl <changhyl@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 19:23:25 by changhyl          #+#    #+#             */
/*   Updated: 2023/10/13 20:31:38 by changhyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

typedef struct s_rgb
{
	int	red;
	int	green;
	int	blue;
}	t_rgb;

typedef struct s_data
{
	int			fd;
	char		**map;
	t_checker	*checker;
	char		*north;
	char		*south;
	char		*west;
	char		*east;
	t_rgb		*floor;
	t_rgb		*ceiling;
	int			map_w;
	int			map_h;
}	t_data;

typedef struct s_checker
{
	int	north;
	int	south;
	int	west;
	int	east;
	int	ceiling;
	int	floor;
}	t_checker;

typedef struct s_mapline
{
	char			*line;
	struct s_list	*next;
}	t_mapline;

void	print_error(const char *s);
int		check_arg(int argc, char *argv[]);
int		ft_atoi(const char *str);

#endif
