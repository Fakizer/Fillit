/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtiterin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 09:23:03 by vtiterin          #+#    #+#             */
/*   Updated: 2016/11/28 09:23:09 by vtiterin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define BUF_SIZE 4096
# define FALSE 0
# define TRUE 1
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef	struct		s_tetr
{
	char			**tetr;
	char			symb;
	int				h;
	int				w;
	struct s_tetr	*next;
}					t_tetr;

char				*ft_read(char *arvg);
int					ft_words(char const *str, char c);
char				**ft_fl_strsplit(char *s, char c);
int					ft_tetr_h(char *str);
int					ft_tetr_w(char *str);
void				ft_tetr_start(char *str, int *st_x, int *st_y);
char				**ft_tetromino(char *str, int h, int w);
t_tetr				*ft_tetrnew(char *str, char ch);
t_tetr				*ft_mylist(char **arr);
void				ft_print_tab(char			**tab);
int					ft_num_mult(int symbol);
char				**ft_maintab(int size);
void				ft_cl_tetr(t_tetr *list, char **tab, int x, int y);
void				ft_wr_tetr(t_tetr *list, char **tab, int x, int y);
int					ft_correct_pos(t_tetr *list, char **tab, int x, int y);
int					ft_tetr_bust(t_tetr *list, char **tab, int size);
void				ft_free_tab(char **tab);
char				**ft_logic(t_tetr *list, int size);
void				ft_fillit(char	**argv);
void				ft_tetr_del(t_tetr *alst);
void				ft_checks(char *str);
void				ft_neighbor(char *s);
int					ft_sdn(char *s);
void				ft_newline(char *s);
int					ft_ch_tabsize(t_tetr *list, char **tab, int size, int *g);

#endif
