/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xalbizu- <xalbizu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 12:36:19 by xalbizu-          #+#    #+#             */
/*   Updated: 2022/09/08 17:57:14 by xalbizu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_lib.h"

int	zoom(t_fdf *data, int z)
{
	data->zoom += z;
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	draw(data, &data->dr);
	return (0);
}

int	translate(int x, int y, t_fdf *data)
{
	data->x_offset += x;
	data->y_offset += y;
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	draw(data, &data->dr);
	return (0);
}

int	deal_key(int key, t_fdf *data)
{
	if (key == 53)
		exit_program(data);
	else if (key == 78)
		zoom(data, -1);
	else if (key == 69)
		zoom(data, 1);
	else if (key == 124)
		translate(20, 0, data);
	else if (key == 123)
		translate(-20, 0, data);
	else if (key == 125)
		translate(0, 20, data);
	else if (key == 126)
		translate(0, -20, data);
	return (0);
}

int	exit_program(t_fdf *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	exit(0);
}

int	main(int argc, char *argv[])
{
	t_fdf	data;
	t_draw	dr;

	if (argc == 2)
	{
		data.min_z = __INT_MAX__;
		data.max_z = -__INT_MAX__;
		data.color_grad = 0;
		data.color = 0xf25353;
		data.x_offset = 0;
		data.y_offset = 0;
		read_file(&data, argv[1]);
		data.mlx_ptr = mlx_init();
		data.win_ptr = mlx_new_window(data.mlx_ptr, 1000, 1000, "FDF");
		data.zoom = 500 / data.height;
		draw(&data, &dr);
		data.dr = dr;
		mlx_hook(data.win_ptr, 17, 0, exit_program, &data);
		mlx_key_hook(data.win_ptr, deal_key, &data);
		mlx_loop(data.mlx_ptr);
	}
	else
		write(1, "Error: 1 arguments expected (./fdf <file with map>)", 52);
	return (0);
}
