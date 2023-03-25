/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moharras <moharras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 16:20:49 by moharras          #+#    #+#             */
/*   Updated: 2020/11/24 16:36:54 by moharras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	sp_side(t_var *v)
{
	if (v->side == 0)
	{
		if (v->mp_x - v->pos_x > 0)
			v->color = v->data_so[v->tex_width * v->tex_y + v->tex_x];
		else
			v->color = v->data_no[v->tex_width * v->tex_y + v->tex_x];
	}
	else
	{
		if (v->mp_y - v->pos_y > 0)
			v->color = v->data_we[v->tex_width * v->tex_y + v->tex_x];
		else
			v->color = v->data_ea[v->tex_width * v->tex_y + v->tex_x];
	}
}

void	coord_tex(t_var *v)
{
	if (v->side == 0)
		v->walx = v->pos_y + v->pw_dst * v->rd_y;
	else
		v->walx = v->pos_x + v->pw_dst * v->rd_x;
	v->walx -= floor(v->walx);
	v->tex_x = (int)(v->walx * (double)v->tex_width);
	if (v->side == 0 && v->rd_x > 0)
		v->tex_x = v->tex_width - v->tex_x - 1;
	if (v->side == 1 && v->rd_y < 0)
		v->tex_x = v->tex_width - v->tex_x - 1;
	v->step = 1.0 * v->tex_height / v->l_h;
	v->tex_pos = (v->ds - v->rs_h / 2 + v->l_h / 2) * v->step;
	while (v->ds < v->d_end)
	{
		v->tex_y = (int)v->tex_pos;
		v->tex_pos += v->step;
		sp_side(v);
		v->texture[v->rs_w * v->ds + v->x] = v->color;
		v->ds++;
	}
}

void	start_draw_end(t_var *v)
{
	v->l_h = (int)(v->rs_h / v->pw_dst);
	v->ds = -v->l_h / 2 + v->rs_h / 2;
	if (v->ds < 0)
		v->ds = 0;
	v->d_end = v->l_h / 2 + v->rs_h / 2;
	if (v->d_end > v->rs_h)
		v->d_end = v->rs_h - 1;
}

void	init_raycast(t_var *v)
{
	v->c_x = 2 * v->x / (double)v->rs_w - 1;
	v->rd_x = v->dir_x + v->p_x * v->c_x;
	v->rd_y = v->dir_y + v->p_y * v->c_x;
	v->mp_x = (int)v->pos_x;
	v->mp_y = (int)v->pos_y;
	v->d_dstx = fabs(1 / v->rd_x);
	v->d_dsty = fabs(1 / v->rd_y);
}
