/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotrace.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnielly <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 14:40:51 by pnielly           #+#    #+#             */
/*   Updated: 2021/12/12 13:17:50 by pnielly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOTRACE_H
# define HOTRACE_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_hot {
	int	research_mode;
	int	get_value;
	int	pos;
	int	free;
}	t_hot;

void	init_hot(t_hot *hot);

int		ft_len(char *s);

void	ft_putstr(char *s);

void	ft_bzero(void *s, size_t n);

void	*ft_calloc(size_t count, size_t size);

int		ft_strcmp(char *s, char *d);

char	*ft_strdup(char *s);

int		get_next_line(int fd, char **line);

#endif
