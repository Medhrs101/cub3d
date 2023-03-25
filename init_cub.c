/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cub.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moharras <moharras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 16:31:01 by moharras          #+#    #+#             */
/*   Updated: 2020/11/30 10:06:34 by moharras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./cub3d.h"

void	player_initial(t_var *v)
{
	v->pos_x = v->mp.pos.x + 0.5;
	v->pos_y = v->mp.pos.y + 0.5;
	if (v->mp.card_dir == 'N' || v->mp.card_dir == 'S')
	{
		v->dir_x = (v->mp.card_dir == 'N') ? -1 : 1;
		v->dir_y = 0;
		v->p_x = 0;
		v->p_y = (v->mp.card_dir == 'N') ? 0.66 : -0.66;
	}
	else if (v->mp.card_dir == 'E' || v->mp.card_dir == 'W')
	{
		v->dir_x = 0;
		v->dir_y = (v->mp.card_dir == 'W') ? 1 : -1;
		v->p_x = (v->mp.card_dir == 'W') ? 0.66 : -0.66;
		v->p_y = 0;
	}
}

void	rc_initial(t_var *v)
{
	player_initial(v);
	v->flr.a = (v->flr.r << 16) + (v->flr.g << 8) + v->flr.b;
	v->cl.a = (v->cl.r << 16) + (v->cl.g << 8) + v->cl.b;
	v->m_sp = 0.07;
	v->rt_sp = 0.02;
	v->key_up = 0;
	v->key_down = 0;
	v->key_right = 0;
	v->key_left = 0;
	v->rt_lft = 0;
	v->rt_rgt = 0;
	v->sprit.z_buffer = (double *)malloc(v->rs_w * sizeof(double));
	v->mp.tb[(int)v->pos_x][(int)v->pos_y] = '0';
}

void	initial_tex(t_var *v)
{
	v->xfi_no = mlx_xpm_file_to_image(v->mlx_ptr, v->p_no, &v->tw, &v->th);
	v->xfi_so = mlx_xpm_file_to_image(v->mlx_ptr, v->p_so, &v->tw, &v->th);
	v->xfi_ea = mlx_xpm_file_to_image(v->mlx_ptr, v->p_ea, &v->tw, &v->th);
	v->xfi_we = mlx_xpm_file_to_image(v->mlx_ptr, v->p_we, &v->tw, &v->th);
	v->xfi_s = mlx_xpm_file_to_image(v->mlx_ptr,
			v->p_sp, &v->sprit.spr_w, &v->sprit.spr_h);
	v->data_no = (int *)mlx_get_data_addr(v->xfi_no,
			&v->bits_per_pixel, &v->size_line, &v->endian);
	v->data_so = (int *)mlx_get_data_addr(v->xfi_so,
			&v->bits_per_pixel, &v->size_line, &v->endian);
	v->data_we = (int *)mlx_get_data_addr(v->xfi_we,
			&v->bits_per_pixel, &v->size_line, &v->endian);
	v->data_ea = (int *)mlx_get_data_addr(v->xfi_ea,
			&v->bits_per_pixel, &v->size_line, &v->endian);
	v->data_s = (int *)mlx_get_data_addr(v->xfi_s,
			&v->bits_per_pixel, &v->size_line, &v->endian);
	v->tex_height = v->th;
	v->tex_width = v->tw;
}

void	start_game(t_var *v)
{
	v->mlx_ptr = mlx_init();
	if (v->save == 0)
		if (!(v->win_ptr = mlx_new_window(v->mlx_ptr,
			v->rs_w, v->rs_h, "cub3D")))
			free_cub_exit(v, EXEC_ERROR);
	v->mlx_img = mlx_new_image(v->mlx_ptr, v->rs_w, v->rs_h);
	initial_tex(v);
	if (v->save == 0)
	{
		mlx_hook(v->win_ptr, 2, 1L << 0, key_press, v);
		mlx_hook(v->win_ptr, 3, 1L << 1, key_release, v);
		mlx_hook(v->win_ptr, 17, 1L << 5, close_window, v);
	}
	mlx_loop_hook(v->mlx_ptr, draw_walls, v);
	mlx_loop(v->mlx_ptr);
}

void	cub_initial(t_var *v)
{
	v->rs_w = -1;
	v->rs_h = -1;
	v->mp.axe.x = -1;
	v->mp.axe.y = -1;
	v->mp.pos.y = -1;
	v->mp.tmp_mp = NULL;
	v->p_no = NULL;
	v->p_so = NULL;
	v->p_we = NULL;
	v->p_ea = NULL;
	v->p_sp = NULL;
	v->sprit.z_buffer = NULL;
	color_init(&v->flr);
	color_init(&v->cl);
	v->mp.val_dir = 0;
	v->sprite.val_sp = 0;
}
