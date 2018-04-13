/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_for_read.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtiterin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 07:11:40 by vtiterin          #+#    #+#             */
/*   Updated: 2016/12/02 07:11:43 by vtiterin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

char	*ft_read(char *arvg)
{
	int		fd;
	int		i;
	char	*buf;

	fd = open(arvg, O_RDONLY);
	if (fd == -1)
	{
		write(1, "error\n", 6);
		exit(1);
	}
	buf = malloc(BUF_SIZE);
	i = read(fd, buf, BUF_SIZE);
	buf[i] = '\0';
	close(fd);
	return (buf);
}

int		ft_words(char const *str, char c)
{
	int	words;
	int	i;

	words = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] && str[i] == c && str[i + 1] == c)
			words++;
		i++;
	}
	return (words + 1);
}

char	**ft_fl_strsplit(char *s, char c)
{
	char	**tab;
	size_t	x;

	x = 0;
	if (!(tab = (char**)malloc(sizeof(char*) * ((ft_words(s, c) + 1)))))
		return (NULL);
	tab[ft_words(s, c)] = NULL;
	while (*s)
	{
		tab[x] = ft_strnew(20);
		if (tab[x] == NULL)
			return (NULL);
		ft_strncpy(tab[x++], s, 20);
		s = s + 21;
	}
	return (tab);
}
