/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xalbizu- <xalbizu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 12:36:19 by xalbizu-          #+#    #+#             */
/*   Updated: 2022/09/02 16:48:51 by xalbizu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_lib.h"

/* void checkmatrix(int height, int width, int **matrix)
{
	for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < width; j++)
			{
				printf("%d ", matrix[i][j]);
			}
			printf("\n");
		}
} */

int	deal_key(int key)
{
	write(1, &key, 11);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_fdf	*data;
	t_draw	*dr;

	if (argc == 2)
	{
		dr = (t_draw *)malloc(sizeof(t_fdf));
		data = (t_fdf *)malloc(sizeof(t_fdf));
		read_file(data, argv[1]);
		data->mlx_ptr = mlx_init();
		data->win_ptr = mlx_new_window(data->mlx_ptr, 1000, 1000, "FDF");
		data->zoom = 20;
		draw(data, dr);
		mlx_key_hook(data->win_ptr, deal_key, NULL);
		mlx_loop(data->mlx_ptr);
	}
	else
		write(1, "Error: 1 arguments expected (./fdf <file with map>)", 52);
	return (0);
}
