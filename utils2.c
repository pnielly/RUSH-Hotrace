/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnielly <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 12:47:42 by pnielly           #+#    #+#             */
/*   Updated: 2021/12/12 16:42:07 by pnielly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

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

void	init_hot(t_hot *hot)
{
	hot->research_mode = 0;
	hot->get_value = 0;
	hot->free = 0;
	hot->pos = 0;
}

/**
 * free tab and tab2
 **/
void	free_all(char **tab, char **tab2, t_hot *hot)
{
	int	r;

	r = -1;
	while (++r < TAB_SIZE)
	{
		if (tab[r])
			free(tab[r]);
		if (tab2[r])
			free(tab2[r]);
	}
	free(tab);
	free(tab2);
	free(hot);
}
