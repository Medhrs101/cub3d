/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transposed.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moharras <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 19:15:44 by moharras          #+#    #+#             */
/*   Updated: 2020/11/24 19:18:38 by moharras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void				transposed_1(t_var *v)
{
	int				i;
	int				j;

	v->buff = (char **)malloc(sizeof(char *) * (v->mp.axe.y + 1));
	i = -1;
	while (++i < v->mp.axe.y)
	{
		j = -1;
		v->buff[i] = malloc(sizeof(char) * (v->mp.axe.x + 1));
		while (++j < v->mp.axe.x)
			v->buff[i][j] = ' ';
		v->buff[i][j] = '\0';
	}
	v->buff[i] = NULL;
}

int					transposed(t_var *v)
{
	int				i;
	int				j;

	transposed_1(v);
	j = -1;
	while (++j < v->mp.axe.y)
	{
		i = -1;
		while (++i < v->mp.axe.x)
			if (j < (int)ft_strlen(v->mp.tb[i]))
				v->buff[j][i] = v->mp.tb[i][j];
	}
	j = -1;
	v->mp.flag = 1;
	while (++j < v->mp.axe.y)
	{
		if (vrf_line_map(v, v->buff[j], 0))
		{
			free_tab2d(v->buff, tab_len(v->buff));
			return (1);
		}
	}
	free_tab2d(v->buff, tab_len(v->buff));
	return (0);
}
