/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dquartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 10:25:52 by dquartin          #+#    #+#             */
/*   Updated: 2018/04/16 18:02:19 by dquartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		**get_coord(char **tab, t_tab **pixel)
{
	int		i;
	int		j;
	int		**coord;
	char	**tmp;

	i = 0;
	if (!((*pixel) = (t_tab*)malloc(sizeof(t_tab))))
		return (0);
	if (!(coord = (int**)malloc(sizeof(int*) * (i + 1))))
		return (0);
	while (tab[i])
	{
		tmp = ft_strsplit(tab[i], ' ');
		j = 0;
		if (!(coord[i] = (int*)malloc(sizeof(int) * tab_len(tmp))))
			return (0);
		while (tmp[j])
		{
			coord[i][j] = ft_atoi(tmp[j]);
			j++;
		}
		(*pixel)->x = j;
		coord = ft_realloc(coord, (i + 1) * INT, (i + 2) * INT);
		delete_tab(&tmp);
		i++;
	}
	(*pixel)->y = i;
	(*pixel)->coord = coord;
	ft_putnbr((*pixel)->y);
	ft_putnbr((*pixel)->x);
	return (coord);
}

int		check_error(char **tab)
{
	int		len;
	int		i;
	int		j;
	char	**tmp;

	i = 0;
	tmp = ft_strsplit(tab[i], ' ');
	len = tab_len(tmp);
	delete_tab(&tmp);
	while (tab[i])
	{
		tmp = ft_strsplit(tab[i], ' ');
		if (tab_len(tmp) != len)
			return (0);
		delete_tab(&tmp);
		j = 0;
		while (tab[i][j])
		{
			if (ft_isdigit(tab[i][j]))
			{
				if (j == (int)ft_strlen(tab[i]))
				{
					if (!ft_isdigit(tab[i][j]) && tab[i][j + 1] != '\0')
						return (0);
				}
			}
			else if (tab[i][j] == ',' && ft_isdigit(tab[i][j + 1]))
			{
				while (tab[i][j] != ' ')
					j++;
			}
			j++;
		}
		i++;
	}
	return (1);
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
	int		**coord;
	char	**tab;
	t_tab	*pixels;

	if (ac == 1)
	{
		ft_puterror("Error: no such map given.");
		return (1);
	}
	if ((fd = open(av[1], O_RDONLY)) == -1)
	{
		ft_puterror("Error: there is a problem with the file descriptor.");
		return (1);
	}
	if ((tab = stock_line(&fd)) == NULL)
		return (1);
	if ((check_error(tab)) == 0)
	{
		ft_puterror("Error: invalid map.");
		return (1);
	}
	if ((coord = get_coord(tab, &pixels)) == 0)
		return (1);
	// fonction pour free int **
	init_fdf(&pixels);
	return (0);
}
