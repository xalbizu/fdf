/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xalbizu- <xalbizu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 11:03:36 by xalbizu-          #+#    #+#             */
/*   Updated: 2022/08/17 15:20:40 by xalbizu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlengnl(char *s1)
{
	int	i;

	i = 0;
	if (!s1)
		return (0);
	while (s1[i] != '\0')
		i++;
	return (i);
}

char	*ft_strndup(char *src, int size)
{
	int		i;
	char	*dest;

	i = 0;
	if (!src || !*src)
		return (0);
	dest = (char *)malloc(sizeof(char) * size + 1);
	if (!dest)
		return (0);
	while (src[i] && i < size)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoingnl(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*dst;

	i = 0;
	j = 0;
	dst = (char *)malloc(sizeof(char)
			* (ft_strlengnl(s1) + ft_strlengnl(s2)) + 1);
	if (!dst)
		return (0);
	while (s1 && s1[i] != '\0')
	{
		dst[i] = s1[i];
		i++;
	}
	while (s2 && s2[j] != '\0')
		dst[i++] = s2[j++];
	dst[i] = '\0';
	return (dst);
}

int	ft_findchar(char *s1)
{
	if (!s1)
		return (0);
	while (*s1 && *s1 != '\n')
		s1++;
	if (*s1 == '\n')
		return (1);
	return (0);
}
