/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtiterin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 07:11:25 by vtiterin          #+#    #+#             */
/*   Updated: 2016/12/02 07:11:28 by vtiterin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

void	ft_newline(char *s)
{
	int n;
	int sh;
	int r;

	n = 0;
	sh = 0;
	while (*s)
	{
		if (*s == '#')
			sh++;
		if (*s == '\n')
			n++;
		s++;
	}
	r = n - sh;
	if (r >= sh / 4)
	{
		write(1, "error\n", 6);
		exit(1);
	}
}

int		ft_sdn(char *s)
{
	int		j;
	int		sh;
	int		new;
	int		dot;

	j = 0;
	sh = 0;
	dot = 0;
	new = 0;
	while (j < 20 && s[j])
	{
		if (s[j] == '#')
			sh++;
		if (s[j] == '.')
			dot++;
		if (s[j] == '\n')
			new++;
		j++;
	}
	if ((sh != 4 || dot != 12 || new != 4) || (s[j] != '\n' && s[j] != '\0'))
	{
		write(1, "error\n", 6);
		exit(1);
	}
	return (j);
}

void	ft_neighbor(char *s)
{
	int grille;
	int i;

	i = 0;
	grille = 0;
	while (i < 20 && s[i])
	{
		if (s[i] == '#')
		{
			if ((i + 1) < 20 && s[i + 1] == '#')
				grille++;
			if ((i - 1) >= 0 && s[i - 1] == '#')
				grille++;
			if ((i + 5) < 20 && s[i + 5] == '#')
				grille++;
			if ((i - 5) >= 0 && s[i - 5] == '#')
				grille++;
		}
		i++;
	}
	if (grille != 8 && grille != 6)
	{
		write(1, "error\n", 6);
		exit(1);
	}
}

void	ft_checks(char *str)
{
	char	*my_str;
	int		i;
	int		j;

	my_str = str;
	i = 0;
	while (my_str[i])
	{
		j = ft_sdn(&my_str[i]);
		ft_neighbor(&my_str[i]);
		i = i + j + 1;
	}
	ft_newline(str);
}
