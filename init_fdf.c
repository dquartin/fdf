/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fdf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dquartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 15:26:27 by dquartin          #+#    #+#             */
/*   Updated: 2018/04/16 18:02:15 by dquartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		deal_key(int key, void *param)
{
	(void)param;
	ft_putnbr(key);
	return (0);
}

void    horizontal_seg(int i, int j, t_init *init)
{
	int        max;

	max = i + 10;
	while (i < max)
	{
		mlx_pixel_put(init->mlx_ptr, init->win_ptr, i, j, 0xFFFFFF);
		i++;
	}
}

void    vertical_seg(int i, int j, t_init *init)
{
	int        max;

	max = j + 10;
	while (j < max)
	{
		mlx_pixel_put(init->mlx_ptr, init->win_ptr, i, j, 0xFFFFFF);
		j++;
	}
}

void    trace_all_segs(t_tab **pixels, t_init *init)
{
	int        i;
	int        j;

	i = 0;
	j = 0;
	while (j < (*pixels)->x)
	{
		i = 0;
		while (i < (*pixels)->y)
		{
			if (j + 1 < (*pixels)->x)
				horizontal_seg(j * 10, i * 10, init);
			if (i + 1 < (*pixels)->y)
				vertical_seg(j * 10, i * 10, init);
			i++;
		}
		j++;
	}
}

void	init_fdf(t_tab **pixels)
{
	int		i;
	int		j;
	t_init	*init;

	i = 0;
	if (!(init = (t_init*)malloc(sizeof(t_init))))
		return ;
	init->mlx_ptr = mlx_init();
	init->win_ptr = mlx_new_window(init->mlx_ptr, 1000, 1000, "fdf");
	while (i < (*pixels)->x)
	{
		j = 0;
		while (j < (*pixels)->y)
		{
			mlx_pixel_put(init->mlx_ptr, init->win_ptr, i * 10, j * 10, 0xFFFFFF);
			j++;
		}
		i++;
	}
	trace_all_segs(pixels, init);
	mlx_key_hook(init->win_ptr, deal_key, (void*)0);
	mlx_loop(t_init->mlx_ptr);
}
