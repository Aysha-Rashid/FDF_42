/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayal-ras <ayal-ras@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 12:45:02 by ayal-ras          #+#    #+#             */
/*   Updated: 2023/12/23 16:10:36 by ayal-ras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	do_key(int numpad, t_fdf **matrix)
{
	t_fdf	*data;

	data = *matrix;
	if (numpad == 69)
		data->scale += 3;
	if (numpad == 78)
		data->scale -= 3;
	if (numpad == 91)
		data->z_scale += 1;
	if (numpad == 84)
		data->z_scale -= 1;
	if (numpad == 87)
	{
		if (data->yes_isometric == 1)
			data->yes_isometric = 0;
		else
			data->yes_isometric = 1;
	}
	rotation(numpad, matrix);
}

void	rotation(int numpad, t_fdf **matrix)
{
	t_fdf	*data;

	data = *matrix;
	if (numpad == 89)
		data->angle_x += 0.05;
	if (numpad == 92)
		data->angle_x -= 0.05;
	if (numpad == 86)
		data->angle_y += 0.05;
	if (numpad == 83)
		data->angle_y -= 0.05;
	if (numpad == 88)
		data->angle_z += 0.05;
	if (numpad == 85)
		data->angle_z -= 0.05;
}

void	arrows(int key, t_fdf **matrix)
{
	t_fdf	*data;

	data = *matrix;
	if (key == 126)
		data->y1 -= 10;
	if (key == 125)
		data->y1 += 10;
	if (key == 123)
		data->x1 -= 10;
	if (key == 124)
		data->x1 += 10;
	if (key == 53)
	{
		mlx_destroy_window(data->mlx_ptr, data->mlx_win);
		exit(0);
		free(matrix);
	}
}

int	deal_key(int key, t_fdf **matrix)
{
	t_fdf	*data;
	int		i;

	i = 0;
	data = *matrix;
	mlx_clear_window(data->mlx_ptr, data->mlx_win);
	ft_memset(data->img_add, 0, W_LENGTH * W_WIDTH * 4);
	do_key(key, matrix);
	arrows(key, matrix);
	draw(matrix);
	return (0);
}

int	clear(void *data)
{
	(void) data;
	exit(0);
	return (0);
}
