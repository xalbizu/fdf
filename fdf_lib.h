/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_lib.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xalbizu- <xalbizu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 12:45:01 by xalbizu-          #+#    #+#             */
/*   Updated: 2022/09/08 17:47:43 by xalbizu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_LIB_H
# define FDF_LIB_H

# include "libft/libft.h"
# include "gnl/get_next_line.h"
# include "minilibx/mlx.h"
# include <math.h>

typedef struct s_draw
{
	float	x;
	float	y;
	float	x1;
	float	y1;
}			t_draw;

typedef struct s_fdf
{
	int		width;
	int		height;
	int		**matrix;
	int		zoom;
	int		color;
	int		x_offset;
	int		y_offset;
	int		max_z;
	int		min_z;
	float	color_grad;
	int		colours[2][13];

	void	*mlx_ptr;
	void	*win_ptr;
	t_draw	dr;
}			t_fdf;

int		get_height(char *file_name);
void	read_file(t_fdf *data, char *file_name);
int		get_width(char *file_name);
void	bresenham(t_draw *dr, t_fdf *data);
void	draw(t_fdf *data, t_draw *dr);
void	isometric(float *x, float *y, int z);
void	fit_to_screen(t_fdf *data, t_draw *dr);
int		exit_program(t_fdf *data);
void	set_colours(t_fdf *data);

#endif