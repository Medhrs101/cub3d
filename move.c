/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moharras <moharras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 16:39:05 by moharras          #+#    #+#             */
/*   Updated: 2020/11/24 16:44:28 by moharras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./cub3d.h"

void	move_up(t_var *v)
{
	if (v->mp.tb[(int)(v->pos_x + v->dir_x * v->m_sp)][(int)v->pos_y] == '0')
		v->pos_x += v->dir_x * v->m_sp;
	if (v->mp.tb[(int)v->pos_x][(int)(v->pos_y + v->dir_y * v->m_sp)] == '0')
		v->pos_y += v->dir_y * v->m_sp;
}

void	move_down(t_var *v)
{
	if (v->mp.tb[(int)(v->pos_x - v->dir_x * v->m_sp)][(int)v->pos_y] == '0')
		v->pos_x -= v->dir_x * v->m_sp;
	if (v->mp.tb[(int)v->pos_x][(int)(v->pos_y - v->dir_y * v->m_sp)] == '0')
		v->pos_y -= v->dir_y * v->m_sp;
}

void	move_right(t_var *v)
{
	if (v->mp.tb[(int)(v->pos_x + v->p_x * v->m_sp)][(int)v->pos_y] == '0')
		v->pos_x += v->p_x * v->m_sp;
	if (v->mp.tb[(int)v->pos_x][(int)(v->pos_y + v->p_y * v->m_sp)] == '0')
		v->pos_y += v->p_y * v->m_sp;
}

void	move_left(t_var *v)
{
	if (v->mp.tb[(int)(v->pos_x - v->p_x * v->m_sp)][(int)v->pos_y] == '0')
		v->pos_x -= v->p_x * v->m_sp;
	if (v->mp.tb[(int)v->pos_x][(int)(v->pos_y - v->p_y * v->m_sp)] == '0')
		v->pos_y -= v->p_y * v->m_sp;
}
