/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_logic.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtiterin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 07:12:59 by vtiterin          #+#    #+#             */
/*   Updated: 2016/12/02 07:13:03 by vtiterin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

char	**ft_logic(t_tetr *list, int size)
{
	char	**tab;
	int		g;

	g = 0;
	tab = ft_maintab(size);
	if (!ft_ch_tabsize(list, tab, size, &g))
		size++;
	ft_free_tab(tab);
	tab = ft_maintab(size);
	ft_tetr_bust(list, tab, size);
	return (tab);
}

int		ft_ch_tabsize(t_tetr *list, char **tab, int size, int *g)
{
	int	i;
	int	j;

	if (!list)
		return (TRUE);
	j = 0;
	while (j <= size - list->h)
	{
		i = 0;
		while (i <= size - list->w)
		{
			if (ft_correct_pos(list, tab, i, j))
			{
				if (ft_ch_tabsize(list->next, tab, size, g))
					return (TRUE);
				else
					ft_cl_tetr(list, tab, i, j);
			}
			i++;
		}
		j++;
		if ((*g)++ > 20000000)
			return (FALSE);
	}
	return (FALSE);
}

int		ft_tetr_bust(t_tetr *list, char **tab, int size)
{
	int	i;
	int	j;

	if (!list)
		return (TRUE);
	j = 0;
	while (j <= size - list->h)
	{
		i = 0;
		while (i <= size - list->w)
		{
			if (ft_correct_pos(list, tab, i, j))
			{
				if (ft_tetr_bust(list->next, tab, size))
					return (TRUE);
				else
					ft_cl_tetr(list, tab, i, j);
			}
			i++;
		}
		j++;
	}
	return (FALSE);
}

int		ft_correct_pos(t_tetr *list, char **tab, int x, int y)
{
	int	i;
	int	j;

	j = 0;
	while (j < list->h)
	{
		i = 0;
		while (i < list->w)
		{
			if (list->tetr[j][i] == '#' && tab[y + j][x + i] != '.')
				return (FALSE);
			i++;
		}
		j++;
	}
	ft_wr_tetr(list, tab, x, y);
	return (TRUE);
}
