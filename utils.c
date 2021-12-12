/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnielly <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 12:47:42 by pnielly           #+#    #+#             */
/*   Updated: 2021/12/12 12:59:03 by pnielly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	if (!s)
		return ;
	i = 0;
	while (i < n)
	{
		*(char *)(s + i) = 0;
		i++;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = (void *)malloc(count * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, count);
	return (ptr);
}

int	ft_strcmp(char *s, char *d)
{
	int	i;

	i = 0;
	if (!s || !d)
		return (1);
	while (s[i] && d[i])
	{
		if ((unsigned char)s[i] != (unsigned char)d[i])
			return (s[i] - d[i]);
		i++;
	}
	if (s[i] || d[i])
		return (s[i] - d[i]);
	return (0);
}

char	*ft_strdup(char *s)
{
	int		len;
	char	*d;

	if (!s)
		return (NULL);
	len = ft_len(s);
	d = malloc(sizeof(char) * (len + 1));
	if (!d)
		return (NULL);
	d[len] = 0;
	while (--len >= 0)
		d[len] = s[len];
	return (d);
}
