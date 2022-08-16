/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xalbizu- <xalbizu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 13:44:45 by xalbizu-          #+#    #+#             */
/*   Updated: 2022/08/15 14:12:30 by xalbizu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFFER_SIZE 1
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

void	updateline(char *line, int size);
char	*get_next_line(int fd);
void	buffer(char *buf, int size);
char	*ft_strjoingnl(char *s1, char *s2);
int		ft_strlengnl(char *s1);
int		ft_findchar(char *s1);
char	*ft_strndup(char *src, int size);

#endif