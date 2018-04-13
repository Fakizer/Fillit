/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_for_tab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtiterin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 07:12:28 by vtiterin          #+#    #+#             */
/*   Updated: 2016/12/02 07:12:29 by vtiterin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

int		ft_num_mult(int symbol)
{
	int c;

	c = 2;
	while (c * c < symbol)
		c++;
	return (c);
}

char	**ft_maintab(int size)
{
	char	**tab;
	int		i;

	if (!(tab = (char**)malloc(sizeof(char*) * (size + 1))))
		return (NULL);
	tab[size] = NULL;
	i = 0;
	while (i < size)
	{
		if (!(tab[i] = ft_strnew(size)))
			return (NULL);
		ft_memset(tab[i], '.', size);
		i++;
	}
	return (tab);
}

void	ft_free_tab(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
		ft_memdel((void**)&tab[i]);
		i++;
	}
	ft_memdel((void **)&tab);
}
