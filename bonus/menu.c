/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayal-ras <ayal-ras@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 12:29:39 by ayal-ras          #+#    #+#             */
/*   Updated: 2023/12/23 16:11:10 by ayal-ras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_menu(t_fdf param)
{
	char	*menu;
	int		y;

	y = 0;
	menu = "move picture = up, down, left, right";
	mlx_string_put(param.mlx_ptr, param.mlx_win, 15, y += 20, TEXT_COLOR, menu);
	menu = "3d(isometric) /2d mode(parallel) = press '5'";
	mlx_string_put(param.mlx_ptr, param.mlx_win, 15, y += 35, TEXT_COLOR, menu);
	menu = "zoom = +, -";
	mlx_string_put(param.mlx_ptr, param.mlx_win, 15, y += 35, TEXT_COLOR, menu);
	menu = "z_scale = 8, 2";
	mlx_string_put(param.mlx_ptr, param.mlx_win, 15, y += 30, TEXT_COLOR, menu);
	menu = "x_rotation = 7, 9";
	mlx_string_put(param.mlx_ptr, param.mlx_win, 15, y += 30, TEXT_COLOR, menu);
	menu = "y_rotation = 4, 1";
	mlx_string_put(param.mlx_ptr, param.mlx_win, 15, y += 30, TEXT_COLOR, menu);
	menu = "z_rotation = 6, 3";
	mlx_string_put(param.mlx_ptr, param.mlx_win, 15, y += 30, TEXT_COLOR, menu);
}
