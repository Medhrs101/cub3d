/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moharras <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 16:44:34 by moharras          #+#    #+#             */
/*   Updated: 2020/11/24 16:44:50 by moharras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rot_right(t_var *v)
{
	v->old_dir_x = v->dir_x;
	v->dir_x = v->dir_x * cos(-v->rt_sp) - v->dir_y * sin(-v->rt_sp);
	v->dir_y = v->old_dir_x * sin(-v->rt_sp) + v->dir_y * cos(-v->rt_sp);
	v->old_p_x = v->p_x;
	v->p_x = v->p_x * cos(-v->rt_sp) - v->p_y * sin(-v->rt_sp);
	v->p_y = v->old_p_x * sin(-v->rt_sp) + v->p_y * cos(-v->rt_sp);
}

void	rot_left(t_var *v)
{
	v->old_dir_x = v->dir_x;
	v->dir_x = v->dir_x * cos(-v->rt_sp) + v->dir_y * sin(-v->rt_sp);
	v->dir_y = -v->old_dir_x * sin(-v->rt_sp) + v->dir_y * cos(-v->rt_sp);
	v->old_p_x = v->p_x;
	v->p_x = v->p_x * cos(-v->rt_sp) + v->p_y * sin(-v->rt_sp);
	v->p_y = -v->old_p_x * sin(-v->rt_sp) + v->p_y * cos(-v->rt_sp);
}
