/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <anclarma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 21:18:51 by anclarma          #+#    #+#             */
/*   Updated: 2021/12/12 16:31:00 by pnielly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>
#include "hotrace.h"
#define BUFFER_SIZE 4096

/*
** get_next_line provisoire
*/

size_t	ft_strlen(const char *s)
{
	size_t	len;

	if (!s)
		return (0);
	len = 0;
	while (s[len])
		len++;
	return (len);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*dst;

	if (!s1 || !s2)
		return (NULL);
	i = ft_strlen(s1) + ft_strlen(s2);
	dst = (char *)malloc(sizeof(char) * (i + 1));
	if (!dst)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		dst[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		dst[i + j] = s2[j];
		j++;
	}
	dst[i + j] = '\0';
	return (dst);
}

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s || !c)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	return (NULL);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	if (!src && !dst)
		return (dst);
	i = 0;
	while (i < n)
	{
		*((unsigned char *)dst + i) = *((unsigned char *)src + i);
		i++;
	}
	return (dst);
}

int	get_next_line(int fd, char **line)
{
	ssize_t	ret;
	char	*str;
	char	*tmp;
	char	buf[2];

	ret = read(fd, buf, 1);
	buf[1] = '\0';
	if (ret <= 0)
		return ((int)ret);
	str = ft_strdup("");
	if (!str)
		return (-1);
	while (ret > 0 && buf[0] != '\n')
	{
		tmp = str;
		str = ft_strjoin(tmp, buf);
		if (!str)
			return (-1);
		free(tmp);
		ret = read(fd, buf, 1);
	}
	*line = str;
	return (1);
}
