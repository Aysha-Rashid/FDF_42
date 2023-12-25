/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayal-ras <ayal-ras@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 12:45:09 by ayal-ras          #+#    #+#             */
/*   Updated: 2023/12/23 16:12:02 by ayal-ras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_fdf	**read_map(char *file)
{
	t_fdf	**matrix_of_dots;
	int		y;
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY);
	matrix_of_dots = memory_allocated(file);
	y = 0;
	line = get_next_line(fd);
	while (line)
	{
		get_dots_from_line(line, matrix_of_dots, y++);
		line = get_next_line(fd);
	}
	free(line);
	matrix_of_dots[y] = NULL;
	close(fd);
	return (matrix_of_dots);
}

int	main(int argc, char **argv)
{
	t_fdf	**matrix;
	t_fdf	*data;

	if (argc == 2)
	{
		matrix = read_map(argv[1]);
		ft_init(*matrix);
		draw(matrix);
		data = *matrix;
		mlx_key_hook(data->mlx_win, esc_key, matrix);
		mlx_hook(data->mlx_win, 17, 0, clear, matrix);
		mlx_loop(data->mlx_ptr);
	}
	else if (argc != 2)
	{
		ft_string("One file required with .fdf\n");
		exit(0);
	}
	return (0);
}
