/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtiterin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 07:12:03 by vtiterin          #+#    #+#             */
/*   Updated: 2016/12/02 07:12:04 by vtiterin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

t_tetr	*ft_mylist(char **arr)
{
	t_tetr	*list;
	t_tetr	*start;
	char	ch;
	int		i;

	i = 0;
	ch = 'A';
	list = ft_tetrnew(arr[i++], ch++);
	start = list;
	while (arr[i])
	{
		list->next = ft_tetrnew(arr[i++], ch++);
		list = list->next;
	}
	return (start);
}

void	ft_tetr_del(t_tetr *alst)
{
	t_tetr	*tmp_f;
	t_tetr	*tmp_n;

	tmp_f = alst;
	while (tmp_f)
	{
		tmp_n = tmp_f->next;
		ft_free_tab(tmp_f->tetr);
		free(tmp_f);
		tmp_f = tmp_n;
	}
	alst = NULL;
}
