/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtiterin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 07:12:16 by vtiterin          #+#    #+#             */
/*   Updated: 2016/12/02 07:12:18 by vtiterin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

void	ft_fillit(char **argv)
{
	char	*str;
	char	**tab;
	t_tetr	*new;
	char	**main_tab;
	int		size;

	str = ft_read(argv[1]);
	ft_checks(str);
	tab = ft_fl_strsplit(str, '\n');
	size = ft_num_mult(ft_words(str, '\n') * 4);
	ft_strdel(&str);
	new = ft_mylist(tab);
	ft_free_tab(tab);
	main_tab = ft_logic(new, size);
	ft_tetr_del(new);
	ft_print_tab(main_tab);
	ft_free_tab(main_tab);
}
