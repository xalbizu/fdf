/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_lib.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xalbizu- <xalbizu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 12:45:01 by xalbizu-          #+#    #+#             */
/*   Updated: 2022/08/27 12:23:36 by xalbizu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_LIB_H
# define FDF_LIB_H

# include "libft/libft.h"
# include "gnl/get_next_line.h"
# include "minilibx/mlx.h"

typedef struct s_fdf
{
	int		width;
	int		height;
	int		**matrix;

	void	*mlx_ptr;
	void	*win_ptr;
}			t_fdf;

int		get_height(char *file_name);
void	read_file(t_fdf *data, char *file_name);
int		get_width(char *file_name);

#endif