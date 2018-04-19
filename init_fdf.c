/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fdf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dquartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 15:26:27 by dquartin          #+#    #+#             */
/*   Updated: 2018/04/19 13:57:07 by rdagnaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void	free_tab(int ***tab, int size)
{
	int		i;

	i = 0;
	while (i < size)
	{
		free((*tab)[i]);
		i++;
	}
	free(*tab);
}

void	free_struct(t_all **all)
{
	free((*all)->key);
	free((*all)->init);
	free((*all)->pixels);
	free(*all);
}

int		deal_key(int key, void *v_all)
{
	t_all	*all;

	all = (t_all*)v_all;
	if (key == ESC)
	{
		mlx_clear_window(all->init->mlx_ptr, all->init->win_ptr);
		mlx_destroy_window(all->init->mlx_ptr, all->init->win_ptr);
		free_tab(&(all->pixels->coord), all->pixels->y);
		free_struct(&all);
		exit(-1);
	}
	key == HPLUS ? all->key->height += 2 : all->key->height;
	key == HLESS ? all->key->height -= 2 : all->key->height;
	key == UP ? all->key->move_up += 2 : all->key->move_up;
	key == DOWN ? all->key->move_up -= 2 : all->key->move_up;
	key == RIGHT ? all->key->move_left -= 2 : all->key->move_left;
	key == LEFT ? all->key->move_left += 2 : all->key->move_left;
	mlx_clear_window(all->init->mlx_ptr, all->init->win_ptr);
	trace_all_segs(all);
	return (0);
}

void	set_key(t_all **all)
{
	if (!((*all)->key = (t_key*)malloc(sizeof(t_key))))
		return ;
	(*all)->key->height = 5;
	(*all)->key->move_up = 10;
	(*all)->key->move_left = 10;
}

void	init_fdf(t_all *all)
{
	if (!(all->init = (t_init*)malloc(sizeof(t_init))))
		return ;
	set_key(&all);
	all->init->mlx_ptr = mlx_init();
	all->init->win_ptr = mlx_new_window(all->init->mlx_ptr, WIN, WIN, "fdf");
	trace_all_segs(all);
	mlx_key_hook(all->init->win_ptr, deal_key, all);
	mlx_loop(all->init->mlx_ptr);
}
