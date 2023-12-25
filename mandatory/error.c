/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayal-ras <ayal-ras@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 14:31:26 by ayal-ras          #+#    #+#             */
/*   Updated: 2023/12/23 16:11:42 by ayal-ras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_error(t_fdf *data)
{
	if (!data)
		exit(0);
}

void	image_menu(t_fdf *data)
{
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win,
		data->img, 0, 0);
	print_menu(*data);
}

int	clear(void *data)
{
	(void) data;
	exit(0);
	return (0);
}

int	esc_key(int key, t_fdf **matrix)
{
	t_fdf	*data;

	data = *matrix;
	if (key == 53)
	{
		mlx_destroy_window(data->mlx_ptr, data->mlx_win);
		exit(EXIT_SUCCESS);
		free(matrix);
	}
	return (0);
}

void	handle_color(char **dots, t_fdf **matrix_of_dots, int y, int x)
{
	int	i;

	if (ft_strchr(dots[x], 'x'))
	{
		i = 0;
		while (dots[x][i])
		{
			if (dots[x][i] == '0')
			{
				if (dots[x][i] == 'x' || dots[x][i] == 'X')
					i++;
				i++;
			}
			if (dots[x][i] != 'x')
			{
				matrix_of_dots[y][x].matrix.color = \
				ft_atoi_base(ft_strchr(dots[x], 'x') + 1, 16);
			}
			i++;
		}
	}
	else
		exit (0);
}
