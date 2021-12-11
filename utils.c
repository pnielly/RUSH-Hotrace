/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnielly <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 12:47:42 by pnielly           #+#    #+#             */
/*   Updated: 2021/12/11 13:25:58 by pnielly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_len(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

void	ft_putstr(char *s)
{
	write(1, s, ft_len(s));
}

void
	ft_bzero(void *s, size_t n)
{
	size_t	i;

	if (!s)
		return ;
	i = 0;
	while (i < n)
	{
		*(char*)(s + i) = 0;
		i++;
	}
}

void
	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = (void*)malloc(count * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, count);
	return (ptr);
}

int
	ft_abs(int nbr)
{
	return ((nbr < 0) ? -nbr : nbr);
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

char *ft_strdup(char *s)
{
	int len;
	char *d;

	if (!s)
		return (NULL);
	len = ft_len(s);
	if (!(d = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	d[len] = 0;
	while (--len >= 0)
		d[len] = s[len];
	return (d);
}
	
	static void
	ft_strrev(char *str)
{
	size_t	length;
	size_t	i;
	char	tmp;

	length = ft_len(str);
	i = 0;
	while (i < length / 2)
	{
		tmp = str[i];
		str[i] = str[length - i - 1];
		str[length - i - 1] = tmp;
		i++;
	}
}

char
	*ft_itoa(int n)
{
	char	*str;
	int		is_neg;
	size_t	length;

	is_neg = (n < 0);
	if (!(str = ft_calloc(11 + is_neg, sizeof(*str))))
		return (NULL);
	if (n == 0)
		str[0] = '0';
	length = 0;
	while (n != 0)
	{
		str[length++] = '0' + ft_abs(n % 10);
		n = (n / 10);
	}
	if (is_neg)
		str[length] = '-';
	ft_strrev(str);
	return (str);
}
