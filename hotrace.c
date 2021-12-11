/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotrace.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnielly <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 21:13:49 by pnielly           #+#    #+#             */
/*   Updated: 2021/12/11 13:29:41 by pnielly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#include "utils.c"

#define BUF_SIZE 1000
#define TAB_SIZE 10000

/**
 * if research_mode == 0 : store the keyword-value pair
 * if research_mode == 1 : research the keyword-value pair
 * if get_value == 0 : set the keyword
 * if get_value == 1 : set the value
 *
 * pos == position in tab / tab2
 * free == 1 : need to free tab2[hot.pos] because overwriting data
 **/
typedef struct s_hot
{
	int	research_mode;
	int	get_value;
	int	pos;
	int	free;
}	t_hot;

int	ft_len(char *s);

void	ft_putstr(char *s);

void	*ft_calloc(size_t count, size_t size);

int	ft_abs(int nbr);

char	*ft_itoa(int n);

int	ft_strcmp(char *s, char *d);

char *ft_strdup(char *s);

/**
 * Hashing function
 * 1. The goal is to assign to each keyword a 'unique' position in tab
 * 2. The hash is computed based on the keyword itself.
 **/
unsigned int	ft_hash(char *s)
{
	unsigned int ret = 0;
	int	i = 0;

	while (*s)
	{
		if (i++ % 2)
			ret += *s++;
		else
			ret -= *s++;
	}
	return (ft_abs(ret));
}

/**
 * storing the keywords and the values
 * 1. if the hash is the same for 2 different keywords
 * we'll iter on tab until we find an empty space.
 * 2. if the keyword is already stored, we'll overwrite it with new value
 **/
void	ft_storing_mode(t_hot *hot, char **tab, char **tab2, char *buf)
{
	if (!hot->get_value)
	{
		hot->pos = ft_hash(buf);
		if (tab[hot->pos] && !ft_strcmp(buf, tab[hot->pos]))
			hot->free = 1;
		else
		{
			while (tab[hot->pos])
				hot->pos++;
			tab[hot->pos] = ft_strdup(buf);
		}
		hot->get_value = 1;
	}
	else
	{
		if (hot->free)
		{
			free(tab2[hot->pos]);
			hot->free = 0;
		}
		tab2[hot->pos] = ft_strdup(buf);
		hot->get_value = 0;
	}
}

/**
 * searching the value based on keyword
 * 1. if the keyword's hash leads to an other keyword, 
 * it means that we need to iter a bit on the tab to find the real keyword.
 * (see ft_storing_mode())
 **/
void	ft_research_mode(t_hot hot, char **tab, char **tab2, char *buf)
{
	hot.pos = ft_hash(buf);
	while (ft_strcmp(tab[hot.pos], buf) && tab[hot.pos])
		hot.pos++;
	if (!ft_strcmp(tab[hot.pos], buf))
		ft_putstr(tab2[hot.pos]);
	else
	{
		write(1, buf, ft_len(buf) - 1);
		ft_putstr(": Not found.\n");
	}
}

/**
 * main()
 * 1. tab will store the keywords
 * 2. tab2 will store the values (located at the same position)
 * 3. Both tabs are initialized to 0
 **/ 
int	main(void)
{
	char	buf[BUF_SIZE];
	int	r;
	t_hot	hot;
	char	**tab = (char **)ft_calloc(TAB_SIZE, sizeof(char *));
	char	**tab2 = (char **)ft_calloc(TAB_SIZE, sizeof(char *));

	hot.research_mode = 0;
	hot.get_value = 0;
	hot.free = 0;
	while ((r = read(0, buf, BUF_SIZE - 1)) > 0)
	{
		if (r <= 0)
			return (1);
		buf[r] = 0;
		if (buf[0] == '\n' && buf[1] == 0)
		{
			hot.research_mode = 1;
			continue ;
		}
		if (!hot.research_mode)
			ft_storing_mode(&hot, tab, tab2, buf);
		else
			ft_research_mode(hot, tab, tab2, buf);
	}
	r = -1;
	while (++r <= TAB_SIZE)
	{
		if (tab[r])
			free(tab[r]);
		if (tab2[r])
			free(tab2[r]);
	}
	free(tab);
	free(tab2);
	system("leaks hotrace");
	return (0);
}
