/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moharras <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 16:27:15 by moharras          #+#    #+#             */
/*   Updated: 2020/11/24 16:29:32 by moharras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_line_ceilling(t_var *v)
{
	int				y;

	y = 0;
	while (y < v->ds)
	{
		v->data_fl_cl[(y * v->rs_w) + v->x] = v->cl.a;
		y++;
	}
}

void	draw_line_floor(t_var *v)
{
	int			y;

	y = v->d_end;
	while (y < v->rs_h)
	{
		v->data_fl_cl[(y * v->rs_w) + v->x] = v->flr.a;
		y++;
	}
}

void	dda(t_var *v)
{
	v->hit = 0;
	while (v->hit == 0)
	{
		if (v->s_dstx < v->s_dsty)
		{
			v->s_dstx += v->d_dstx;
			v->mp_x += v->step_x;
			v->side = 0;
		}
		else
		{
			v->s_dsty += v->d_dsty;
			v->mp_y += v->step_y;
			v->side = 1;
		}
		if (v->mp.tb[v->mp_x][v->mp_y] == '1')
			v->hit = 1;
	}
	if (v->side == 0)
		v->pw_dst = (v->mp_x - v->pos_x + (1 - v->step_x) / 2) / v->rd_x;
	else
		v->pw_dst = (v->mp_y - v->pos_y + (1 - v->step_y) / 2) / v->rd_y;
}

void	step_init_dist(t_var *v)
{
	if (v->rd_x < 0)
	{
		v->step_x = -1;
		v->s_dstx = (v->pos_x - v->mp_x) * v->d_dstx;
	}
	else
	{
		v->step_x = 1;
		v->s_dstx = (v->mp_x + 1 - v->pos_x) * v->d_dstx;
	}
	if (v->rd_y < 0)
	{
		v->step_y = -1;
		v->s_dsty = (v->pos_y - v->mp_y) * v->d_dsty;
	}
	else
	{
		v->step_y = 1;
		v->s_dsty = (v->mp_y + 1 - v->pos_y) * v->d_dsty;
	}
}
