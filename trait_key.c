/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trait_key.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moharras <moharras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 18:50:53 by moharras          #+#    #+#             */
/*   Updated: 2020/11/26 11:38:29 by moharras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./cub3d.h"

int		key_release(int key, t_var *v)
{
	if (key == 13)
		v->key_up = 0;
	else if (key == 1)
		v->key_down = 0;
	else if (key == 2)
		v->key_right = 0;
	else if (key == 0)
		v->key_left = 0;
	else if (key == 124)
		v->rt_rgt = 0;
	else if (key == 123)
		v->rt_lft = 0;
	return (0);
}

int		close_window(t_var *v)
{
	free(v->p_no);
	free(v->p_so);
	free(v->p_ea);
	free(v->p_we);
	exit(0);
	return (0);
}

int		key_press(int key, t_var *v)
{
	if (key == 13)
		v->key_up = 1;
	else if (key == 1)
		v->key_down = 1;
	else if (key == 2)
		v->key_right = 1;
	else if (key == 0)
		v->key_left = 1;
	else if (key == 124)
		v->rt_rgt = 1;
	else if (key == 123)
		v->rt_lft = 1;
	else if (key == 53)
		close_window(v);
	return (0);
}

void	trait_key(t_var *v)
{
	if (v->key_up == 1)
		move_up(v);
	if (v->key_down == 1)
		move_down(v);
	if (v->key_right == 1)
		move_right(v);
	if (v->key_left == 1)
		move_left(v);
	if (v->rt_rgt == 1)
		rot_right(v);
	if (v->rt_lft == 1)
		rot_left(v);
}
