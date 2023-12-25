/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayal-ras <ayal-ras@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 16:45:16 by ayal-ras          #+#    #+#             */
/*   Updated: 2023/12/23 16:11:14 by ayal-ras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	get_dots_from_line(char *line, t_fdf **matrix_of_dots, int y)
{
	char	**dots;
	int		x;

	x = 0;
	dots = ft_split(line, ' ');
	ft_error(*matrix_of_dots);
	while (dots[x])
	{
		matrix_of_dots[y][x].matrix.z = ft_atoi(dots[x]);
		matrix_of_dots[y][x].matrix.x = x;
		matrix_of_dots[y][x].matrix.y = y;
		matrix_of_dots[y][x].is_end = 0;
		if (ft_strchr(dots[x], ','))
			handle_color(dots, matrix_of_dots, y, x);
		else
			matrix_of_dots[y][x].matrix.color = -1;
		free (dots[x++]);
	}
	free (dots);
	matrix_of_dots[y][--x].is_end = 1;
	free(line);
}

t_fdf	**memory_allocated(char *file_name)
{
	t_fdf	**new;
	int		x;
	int		y;
	int		fd;
	char	*line;

	fd = open(file_name, O_RDONLY, 0);
	line = get_next_line(fd);
	x = count_substrings(line, ' ');
	y = 0;
	while (line)
	{
		y++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	new = (t_fdf **)malloc(sizeof(t_fdf *) * (y + 1));
	while (y > 0)
		new[--y] = (t_fdf *)malloc(sizeof(t_fdf) * (x + 1));
	ft_error(*new);
	close(fd);
	return (new);
}

void	isometric(t_fdf *dots)
{
	double	angle;

	angle = 0.523599;
	dots->matrix.x = (dots->matrix.x - dots->matrix.y) * cos(angle);
	dots->matrix.y = (dots->matrix.x + dots->matrix.y)
		* sin(angle) - dots->matrix.z;
}
