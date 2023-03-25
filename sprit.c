/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprit.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moharras <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 17:15:02 by moharras          #+#    #+#             */
/*   Updated: 2020/11/24 17:19:42 by moharras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./cub3d.h"

void				count_sprite(t_var *v, int i)
{
	v->sprit.sp_x = 0.5 + v->sprite.coord[v->sprit.sp_ord[i]].x - v->pos_x;
	v->sprit.sp_y = 0.5 + v->sprite.coord[v->sprit.sp_ord[i]].y - v->pos_y;
	v->sprit.inv_det = 1.0 / (v->p_x * v->dir_y - v->dir_x * v->p_y);
	v->sprit.tsf_x = v->sprit.inv_det *
		(v->dir_y * v->sprit.sp_x - v->dir_x * v->sprit.sp_y);
	v->sprit.tsf_y = v->sprit.inv_det *
		(-v->p_y * v->sprit.sp_x + v->p_x * v->sprit.sp_y);
	v->sprit.sp_scrn_x = (int)((v->rs_w / 2) *
			(1 + v->sprit.tsf_x / v->sprit.tsf_y));
	v->sprit.sp_h = abs((int)(v->rs_h / (v->sprit.tsf_y)));
	v->sprit.dr_st_y = -v->sprit.sp_h / 2 + v->rs_h / 2;
	count_sprite_1(v);
}

void				sort_sprite(t_var *v)
{
	int				i;
	int				j;
	int				p;
	double			max;

	i = -1;
	while (++i <= v->sprite.count)
	{
		max = v->sprit.sp_dst[i];
		j = 0;
		while (j <= v->sprite.count)
		{
			if (max <= v->sprit.sp_dst[j])
			{
				max = v->sprit.sp_dst[j];
				p = j;
			}
			j++;
		}
		v->sprit.sp_dst[p] = 0;
		v->sprit.sp_ord[i] = p;
	}
}

void				sprite_1(t_var *v)
{
	int				i;

	i = 0;
	while (i < v->sprite.count)
	{
		v->sprit.sp_ord[i] = i;
		v->sprit.sp_dst[i] = pow((v->pos_x - v->sprite.coord[i].x), 2)
			+ pow((v->pos_y - v->sprite.coord[i].y), 2);
		i++;
	}
	sort_sprite(v);
	sprite_2(v);
}
