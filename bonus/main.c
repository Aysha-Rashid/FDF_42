/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayal-ras <ayal-ras@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 12:45:09 by ayal-ras          #+#    #+#             */
/*   Updated: 2023/12/23 16:11:04 by ayal-ras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_fdf	**read_map(char *file)
{
	t_fdf	**matrix_of_dots;
	int		y;
	int		fd;
	char	*line;

	matrix_of_dots = memory_allocated(file);
	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	if (!matrix_of_dots)
		return (0);
	y = 0;
	while (line)
	{
		get_dots_from_line(line, matrix_of_dots, y);
		line = get_next_line(fd);
		y++;
	}
	free(line);
	matrix_of_dots[y] = NULL;
	close(fd);
	return (matrix_of_dots);
}

int	main(int argc, char **argv)
{
	t_fdf	**matrix;

	if (argc == 2)
	{
		matrix = read_map(argv[1]);
		ft_init(*matrix);
		draw(matrix);
		controls(matrix);
	}
	else if (argc != 2)
	{
		ft_string("One file required with .fdf\n");
		exit(0);
	}
	return (0);
}

void	controls(t_fdf **matrix)
{
	t_fdf	*data;

	data = *matrix;
	if (!data)
		return ;
	mlx_hook(data->mlx_win, 2, 0, deal_key, matrix);
	mlx_hook(data->mlx_win, 17, 0, clear, matrix);
	mlx_loop(data->mlx_ptr);
}
