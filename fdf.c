/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xalbizu- <xalbizu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 12:36:19 by xalbizu-          #+#    #+#             */
/*   Updated: 2022/09/12 10:08:37 by xalbizu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_lib.h"

int	zoom(t_fdf *data, int z)
{
	if ((data->zoom < 3 && z > 0) || data->zoom > 2)
	{
		data->zoom += z;
		mlx_clear_window(data->mlx_ptr, data->win_ptr);
		draw(data, &data->dr);
	}
	return (0);
}

int	translate(int x, int y, t_fdf *data)
{
	data->x_offset += x * (data->zoom * data->height) / 100;
	data->y_offset += y * (data->zoom * data->height) / 100;
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
	else if (key == 18)
		change_colour(data, 0);
	else if (key == 19)
		change_colour(data, 1);
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
		data.sc = 0;
		data.min_z = 2147483647;
		data.max_z = -2147483647;
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
