/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprit_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moharras <moharras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 18:36:35 by moharras          #+#    #+#             */
/*   Updated: 2020/11/26 14:47:32 by moharras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./cub3d.h"

void		count_sprite_1(t_var *v)
{
	if (v->sprit.dr_st_y < 0)
		v->sprit.dr_st_y = 0;
	v->sprit.dr_en_y = v->sprit.sp_h / 2 + v->rs_h / 2;
	if (v->sprit.dr_en_y >= v->rs_h)
		v->sprit.dr_en_y = v->rs_h - 1;
	v->sprit.sp_wdth = abs((int)(v->rs_h / (v->sprit.tsf_y)));
	v->sprit.dr_st_x = -v->sprit.sp_wdth / 2 + v->sprit.sp_scrn_x;
	if (v->sprit.dr_st_x < 0)
		v->sprit.dr_st_x = 0;
	v->sprit.dr_en_x = v->sprit.sp_wdth / 2 + v->sprit.sp_scrn_x;
	if (v->sprit.dr_en_x >= v->rs_w)
		v->sprit.dr_en_x = v->rs_w - 1;
}

void		sprite_3(t_var *v, int stripe)
{
	int	y;

	v->sprit.tex_x = (int)(256 * (stripe - (-v->sprit.sp_wdth / 2 +
	v->sprit.sp_scrn_x)) * v->sprit.spr_w / v->sprit.sp_wdth) / 256;
	if (v->sprit.tsf_y > 0 && stripe > 0 && stripe < v->rs_w &&
			v->sprit.tsf_y < v->sprit.z_buffer[stripe])
	{
		y = v->sprit.dr_st_y;
		while (y < v->sprit.dr_en_y)
		{
			v->sprit.d = (y) * 256 - v->rs_h * 128 + v->sprit.sp_h * 128;
			v->sprit.tex_y = ((v->sprit.d * v->tex_height) /
			v->sprit.sp_h) / 256;
			v->sprit.color = v->data_s[v->sprit.spr_w *
			v->sprit.tex_y + v->sprit.tex_x];
			if (v->sprit.color != 9961608)
				v->texture[y * v->rs_w + stripe] = v->sprit.color;
			y++;
		}
	}
}

void		sprite_2(t_var *v)
{
	int	stripe;
	int	i;

	i = 0;
	while (i < v->sprite.count)
	{
		count_sprite(v, i);
		stripe = v->sprit.dr_st_x;
		while (stripe < v->sprit.dr_en_x)
		{
			sprite_3(v, stripe);
			stripe++;
		}
		i++;
	}
}
