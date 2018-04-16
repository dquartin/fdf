/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dquartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 13:49:16 by dquartin          #+#    #+#             */
/*   Updated: 2018/04/16 18:02:17 by dquartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <fcntl.h>
# include "libft/libft.h"

# define STR sizeof(char*)
# define INT sizeof(int*)
# define ESC 53


typedef struct		s_tab
{
	int		x;
	int		y;
	int		**coord;
}					t_tab;

typedef struct		s_init
{
	void	*mlx_ptr;
	void	*win_ptr;
}					t_init;

void	init_fdf(t_tab **pixels);

#endif
