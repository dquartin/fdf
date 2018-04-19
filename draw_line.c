/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dquartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 20:02:29 by dquartin          #+#    #+#             */
/*   Updated: 2018/04/18 21:41:14 by dquartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_v2	isometric_projection(t_v3 v, int size, t_all *all)
{
	t_v2	v2;

	v2.x = v.x + v.y + (SCALE * all->key->move_left);
	v2.y = (size + v.x - v.y + (-v.z / 2) + (SCALE * all->key->move_up)) / VIEW;
	v2.z = v.z;
	return (v2);
}

#include <stdio.h>

void	trace_seg_v2(t_v2 point1, t_v2 point2, t_all *all)
{
	int		x;
	int		y;
	int		tmp;
	int		alt_color;
	float	pente;
	float	pente_c;

	pente_c = (point2.z - point1.z) / (point2.x - point1.x);
	pente = (point2.y - point1.y) / (point2.x - point1.x);
	x = point1.x;
	alt_color = point1.z;

	printf("alt : %d\n", alt_color);
	printf("pente : %f\n", pente_c);
	printf("delta_size : %d\n", all->pixels->delta_size);
	printf("height : %d\n", all->key->height);
	while (x < point2.x)
	{
		y = pente * (x - point1.x) + point1.y;
		alt_color += pente_c;
		tmp = 0;
		if (pente > PRES)
		{
			while (tmp < pente)
			{
				printf("height : %d\n", all->key->height);
				printf("height : %d\n", all->key->height);
				if (alt_color < -(all->pixels->delta_size / 4))
					mlx_pixel_put(all->init->mlx_ptr, all->init->win_ptr, x, y + tmp, 0x0000FF);
				else if (alt_color > all->pixels->delta_size / 4)
					mlx_pixel_put(all->init->mlx_ptr, all->init->win_ptr, x, y + tmp, 0xFF0000);
				else
					mlx_pixel_put(all->init->mlx_ptr, all->init->win_ptr, x, y + tmp, 0xFFFFFF);
				tmp++;
			}
		}
		else if (pente < -PRES)
		{
			while (tmp > pente)
			{
				if (alt_color < -(all->pixels->delta_size / 4))
					mlx_pixel_put(all->init->mlx_ptr, all->init->win_ptr, x, y + tmp, 0x0000FF);
				else if (alt_color > all->pixels->delta_size / 4)
					mlx_pixel_put(all->init->mlx_ptr, all->init->win_ptr, x, y + tmp, 0xFF0000);
				else
					mlx_pixel_put(all->init->mlx_ptr, all->init->win_ptr, x, y + tmp, 0xFFFFFF);
				tmp--;
			}
		}
		if (alt_color < -(all->pixels->delta_size / 4))
			mlx_pixel_put(all->init->mlx_ptr, all->init->win_ptr, x, y + tmp, 0x0000FF);
		else if (alt_color > all->pixels->delta_size / 4)
			mlx_pixel_put(all->init->mlx_ptr, all->init->win_ptr, x, y + tmp, 0xFF0000);
		else
			mlx_pixel_put(all->init->mlx_ptr, all->init->win_ptr, x, y + tmp, 0xFFFFFF);
		x++;
	}
}

void	trace_seg(t_all *all, int i, int j)
{
	t_v2	p1_projection;
	t_v2	p2_projection;

	if (i + 1 < all->pixels->y)
	{
		p1_projection = isometric_projection((t_v3){i * SCALE, j * SCALE,
				all->pixels->coord[i][j] * all->key->height}, all->pixels->x * SCALE,
				all);
		p2_projection = isometric_projection((t_v3){(i + 1) * SCALE, j * SCALE,
				all->pixels->coord[i + 1][j] * all->key->height}, all->pixels->x * SCALE,
				all);
		trace_seg_v2(p1_projection, p2_projection, all);
	}
	if (j + 1 < all->pixels->x)
	{
		p1_projection = isometric_projection((t_v3){i * SCALE, j * SCALE,
				all->pixels->coord[i][j] * all->key->height}, all->pixels->x * SCALE,
				all);
		p2_projection = isometric_projection((t_v3){i * SCALE, (j + 1) * SCALE,
				all->pixels->coord[i][j + 1] * all->key->height}, all->pixels->x * SCALE,
				all);
		trace_seg_v2(p1_projection, p2_projection, all);
	}
}

void    trace_all_segs(t_all *all)
{
	int        i;
	int        j;

	i = 0;
	j = 0;
	while (i < all->pixels->y)
	{
		j = 0;
		while (j < all->pixels->x)
		{
			trace_seg(all, i, j);
			j++;
		}
		i++;
	}
}
