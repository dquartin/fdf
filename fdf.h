/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dquartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 13:49:16 by dquartin          #+#    #+#             */
/*   Updated: 2018/04/19 15:20:37 by dquartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <fcntl.h>
# include <math.h>
# include "libft/libft.h"

# define STR sizeof(char*)
# define INT sizeof(int*)
# define WIN 1500
# define ESC 53
# define SCALE 20
# define PRES 3
# define VIEW 2
# define UP 125
# define DOWN 126
# define RIGHT 123
# define LEFT 124
# define HPLUS 69
# define HLESS 78

typedef struct	s_v3
{
	float		x;
	float		y;
	float		z;
}				t_v3;

typedef struct	s_v2
{
	float		x;
	float		y;
	float		z;
}				t_v2;

typedef struct	s_tab
{
	int			x;
	int			y;
	int			delta_size;
	int			**coord;
}				t_tab;

typedef	struct	s_key
{
	int			height;
	int			move_up;
	int			move_left;
}				t_key;

typedef struct	s_init
{
	void		*mlx_ptr;
	void		*win_ptr;
}				t_init;

typedef struct	s_all
{
	t_tab		*pixels;
	t_init		*init;
	t_key		*key;
	t_v2		*v2;
	t_v3		*v3;
}				t_all;

void			init_fdf(t_all *all);
void			free_tab(int ***tab, int size);
void			trace_all_segs(t_all *all);

#endif
