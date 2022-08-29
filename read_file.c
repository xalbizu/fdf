/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xalbizu- <xalbizu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 11:54:46 by xalbizu-          #+#    #+#             */
/*   Updated: 2022/08/29 15:03:01 by xalbizu-         ###   ########.fr       */
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

int	*ft_get_nums(char *line, int width)
{
	int		*result;
	int		i;
	int		j;

	j = 0;
	i = 0;
	result = (int *)malloc(width * sizeof(int));
	while (j < width)
	{
		if (line[i] <= '9' && line[i] >= '0')
		{
			result[j] = line[i] - '0';
			while (line[i + 1] <= '9' && line[i + 1] >= '0')
			{
				result[j] = result[j] * 10;
				result[j] = result[j] + line[i + 1] - '0';
				i++;
			}
			j++;
		}
		i++;
	}
	return (result);
}

int	*fill_matrix(char *line, int width)
{
	int	*nums;

	nums = ft_get_nums(line, width);
	return (nums);
}

void	read_file(t_fdf *data, char *file_name)
{
	int		fd;
	char	*line;
	int		i;

	data->height = get_height(file_name);
	data->width = get_width(file_name);
	data->matrix = (int **)malloc(sizeof(int *) * (data->width));
	fd = open(file_name, O_RDONLY, 0);
	i = 0;
	while (i == 0 || i < data->height)
	{
		line = get_next_line(fd);
		data->matrix[i] = fill_matrix(line, data->width);
		free(line);
		i++;
	}
	close(fd);
}
