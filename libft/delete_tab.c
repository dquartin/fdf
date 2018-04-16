/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_tab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dquartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 13:37:41 by dquartin          #+#    #+#             */
/*   Updated: 2018/04/13 15:25:11 by dquartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	delete_tab(char ***stock)
{
	int		i;

	i = 0;
	if (*stock)
	{
		while ((*stock)[i])
		{
			ft_strdel(*(stock) + i);
			i++;
		}
		free(*stock);
		*stock = NULL;
	}
}
