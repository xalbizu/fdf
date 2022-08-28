/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xalbizu- <xalbizu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 11:54:46 by xalbizu-          #+#    #+#             */
/*   Updated: 2022/08/27 15:21:27 by xalbizu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_lib.h"

int	get_height(char *file_name)
{
	char	*line;
	int		fd;
	int		height;

	fd = open(file_name, O_RDONLY, 0);
	height = 0;
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		height++;
	}
	free(line);
	close(fd);
	return (height);
}

int	get_width(char *file_name)
{
	int		width;
	int		fd;
	char	*line;
	int		i;

	width = 0;
	i = 0;
	fd = open(file_name, O_RDONLY, 0);
	line = get_next_line(fd);
	while (line[i])
	{
		if ((line[i] >= '0' && line[i] <= '9')
			&& (line[i + 1] == ' ' || line[i + 1] == '\n'))
			width++;
		i++;
	}
	free(line);
	close(fd);
	return (width);
}

void	fill_matrix(int *z_line, char *line)
{
	char	**nums;

	nums = ft_split(line, ' ');
	i = 0;
	while (nums[i])
	{
		z_line[i] = ft_atoi(nums[i]);
		free(nums[i]);
		i++;
	}
	free(nums);
}

void	read_file(t_fdf *data, char *file_name)
{
	int	fd;
	int	*line;
	int	i;

	data->height = get_height(file_name);
	data->width = get_width(file_name);
	data->matrix = (int **)malloc(sizeof(int *) * (data->width));
	fd = open(file_name, O_RDONLY, 0);
	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		fill_matrix(data->matrix[i], line);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	free(line);
	data->matrix[i] = NULL;
}
