/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotrace.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnielly <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 21:13:49 by pnielly           #+#    #+#             */
/*   Updated: 2021/12/12 16:45:39 by pnielly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

/**
 * Hashing function
 * 1. The goal is to assign to each keyword a 'unique' position in tab
 * 2. The hash is computed based on the keyword itself.
 **/
unsigned int	ft_hash(char *s)
{
	unsigned int	ret;

	ret = 54;
	while (*s)
		ret = ret * 13 + *s++;
	return (ret % TAB_SIZE);
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
		while (tab[hot->pos])
			hot->pos++;
		tab[hot->pos] = ft_strdup(buf);
		hot->get_value = 1;
	}
	else
	{
		free(tab2[hot->pos]);
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
	while (tab[hot.pos] && ft_strcmp(tab[hot.pos], buf))
		hot.pos++;
	if (tab[hot.pos] && !ft_strcmp(tab[hot.pos], buf))
	{
		ft_putstr(tab2[hot.pos]);
		ft_putstr("\n");
	}
	else
	{
		write(1, buf, ft_len(buf));
		ft_putstr(": Not found.\n");
	}
}

void	ft_control(t_hot *hot, char **tab, char **tab2, char *buf)
{
	if (!hot->research_mode)
		ft_storing_mode(hot, tab, tab2, buf);
	else
		ft_research_mode(*hot, tab, tab2, buf);
}

/**
 * main()
 * 1. tab will store the keywords
 * 2. tab2 will store the values (located at the same position)
 * 3. Both tabs are initialized to 0
 **/
int	main(void)
{
	char	*buf;
	t_hot	*hot;
	char	**tab;
	char	**tab2;

	tab = (char **)ft_calloc(TAB_SIZE, sizeof(char *));
	tab2 = (char **)ft_calloc(TAB_SIZE, sizeof(char *));
	hot = (t_hot *)malloc(sizeof(t_hot));
	if (!hot || !tab || !tab2)
		return (-1);
	init_hot(hot);
	while ((get_next_line(0, &buf)) > 0)
	{
		if (buf[0] == 0)
		{
			hot->research_mode = 1;
			free(buf);
			continue ;
		}
		ft_control(hot, tab, tab2, buf);
		free(buf);
		buf = NULL;
	}
	free_all(tab, tab2, hot);
	return (0);
}
