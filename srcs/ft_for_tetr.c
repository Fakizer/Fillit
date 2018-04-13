/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_for_tetr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtiterin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 07:11:52 by vtiterin          #+#    #+#             */
/*   Updated: 2016/12/02 07:11:54 by vtiterin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

int		ft_tetr_h(char *str)
{
	int i;
	int h;

	h = 0;
	while (*str)
	{
		i = 0;
		while (*str != '\n')
		{
			if (*str++ == '#')
				i++;
		}
		if (i != 0)
			h++;
		str++;
	}
	return (h);
}

int		ft_tetr_w(char *str)
{
	int i;
	int x;
	int w;
	int point;

	i = 0;
	w = 0;
	while (str[i] != '\n')
	{
		x = i;
		point = 0;
		while (x < 20)
		{
			if (str[x] == '#')
				point++;
			x += 5;
		}
		if (point != 0)
			w++;
		i++;
	}
	return (w);
}

void	ft_tetr_start(char *str, int *st_x, int *st_y)
{
	int i;

	i = 0;
	while (i < 20)
	{
		if (str[i] == '#')
		{
			if (i / 5 < *st_y)
				*st_y = i / 5;
			if (i % 5 < *st_x)
				*st_x = i % 5;
		}
		i++;
	}
}

t_tetr	*ft_tetrnew(char *str, char ch)
{
	t_tetr	*tmp;

	if (!(tmp = (t_tetr*)malloc(sizeof(*tmp))))
		return (NULL);
	tmp->symb = ch;
	tmp->w = ft_tetr_w(str);
	tmp->h = ft_tetr_h(str);
	tmp->tetr = ft_tetromino(str, tmp->h, tmp->w);
	tmp->next = NULL;
	return (tmp);
}

char	**ft_tetromino(char *str, int h, int w)
{
	char	**tetr;
	int		i;
	int		st_x;
	int		st_y;

	st_y = 3;
	st_x = 3;
	ft_tetr_start(str, &st_x, &st_y);
	if (!(tetr = (char**)malloc(sizeof(char*) * (h + 1))))
		return (NULL);
	tetr[h] = NULL;
	i = 0;
	while (i < h)
	{
		if (!(tetr[i] = ft_strnew(w)))
			return (NULL);
		ft_strncpy(tetr[i], str + (st_x) + (i + st_y) * 5, w);
		i++;
	}
	return (tetr);
}
