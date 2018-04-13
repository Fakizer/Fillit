/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_for_write.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtiterin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 07:12:42 by vtiterin          #+#    #+#             */
/*   Updated: 2016/12/02 07:12:43 by vtiterin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

void	ft_cl_tetr(t_tetr *list, char **tab, int x, int y)
{
	int i;
	int j;

	j = 0;
	while (j < list->h)
	{
		i = 0;
		while (i < list->w)
		{
			if (list->tetr[j][i] == '#')
				tab[y + j][x + i] = '.';
			i++;
		}
		j++;
	}
}

void	ft_wr_tetr(t_tetr *list, char **tab, int x, int y)
{
	int i;
	int j;

	j = 0;
	while (j < list->h)
	{
		i = 0;
		while (i < list->w)
		{
			if (list->tetr[j][i] == '#')
				tab[y + j][x + i] = list->symb;
			i++;
		}
		j++;
	}
}

void	ft_print_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		ft_putstr(tab[i]);
		ft_putchar('\n');
		i++;
	}
}
