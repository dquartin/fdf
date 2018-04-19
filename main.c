/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dquartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 10:25:52 by dquartin          #+#    #+#             */
/*   Updated: 2018/04/19 15:09:04 by dquartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	malloc_struct(t_all **all, int ***coord, int i)
{
	if (!((*all) = (t_all*)malloc(sizeof(t_all))))
		return ;
	if (!((*all)->pixels = (t_tab*)malloc(sizeof(t_tab))))
		return ;
	if (!(*coord = (int**)malloc(sizeof(int*) * (i + 1))))
		return ;
}

int		loop(char **tab, int i, int j, t_all **all)
{
	int		min;
	int		max;

	min = 0;
	max = 0;
	min = (tab[i][j] < min) ? tab[i][j] : min;
	max = (tab[i][j] > max) ? tab[i][j] : max;
	(*all)->pixels->delta_size = max - min;
	j++;
	return (j);
}

int		**get_coord(char **tab, t_all **all)
{
	int		i;
	int		j;
	int		**coord;
	char	**tmp;

	i = 0;
	malloc_struct(all, &coord, i);
	while (tab[i])
	{
		tmp = ft_strsplit(tab[i], ' ');
		j = 0;
		if (!(coord[i] = (int*)malloc(sizeof(int) * tab_len(tmp))))
			return (0);
		while (tmp[j])
		{
			coord[i][j] = ft_atoi(tmp[j]);
			j = loop(tab, i, j, all);
		}
		(*all)->pixels->x = j;
		coord = ft_realloc(coord, (i + 1) * INT, (i + 2) * INT);
		delete_tab(&tmp);
		i++;
	}
	(*all)->pixels->y = i;
	return (coord);
}

char	**stock_line(int *fd)
{
	int		i;
	int		j;
	char	**tab;
	char	*line;

	j = 2;
	if (!(tab = (char**)malloc(sizeof(char*) * j)))
		return (NULL);
	i = 0;
	while ((get_next_line(*fd, &line)) == 1)
	{
		tab[i] = ft_strdup(line);
		ft_strdel(&line);
		tab = ft_realloc(tab, j * STR, (j + 1) * STR);
		j++;
		i++;
	}
	tab[i] = NULL;
	close(*fd);
	return (tab);
}

int		main(int ac, char **av)
{
	int		fd;
	char	**tab;
	t_all	*all;

	if (ac == 1)
	{
		ft_puterror("Usage: ./fdf [map].");
		return (1);
	}
	if ((fd = open(av[1], O_RDONLY)) == -1)
	{
		ft_puterror("Error: there is a problem with the file descriptor.");
		return (1);
	}
	if ((tab = stock_line(&fd)) == NULL)
		return (1);
	if ((all->pixels->coord = get_coord(tab, &all)) == 0)
		return (1);
	init_fdf(all);
	return (0);
}
